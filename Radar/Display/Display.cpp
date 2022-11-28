#include <X11/Xlib.h>
#include <cstdio>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <chrono>

class _Time
{
public:
    _Time()
    {
        start_ = std::chrono::high_resolution_clock::now();
    }

    long time()
    {
        std::chrono::duration<long, std::nano> elap = std::chrono::high_resolution_clock::now() - start_;
        return elap.count();
    }

private:
    std::chrono::high_resolution_clock::time_point start_;
};

struct Point
{
    int x, y;
};

struct Size
{
    int width, height;
};

struct Rect
{
    int x, y;
    int width, height;

    inline Point tl() const
    {
        return {std::min(x, x + width), std::min(y, y + height)};
    }
    inline Point br() const
    {
        return {std::max(x, x + width), std::max(y, y + height)};
    }
    inline Point tr() const
    {
        return {std::max(x, x + width), std::min(y, y + height)};
    }
    inline Point bl() const
    {
        return {std::min(x, x + width), std::max(y, y + height)};
    }
};

inline bool pointInRect(const Point &p, const Rect &r)
{
    return (p.x >= r.tl().x && p.x <= r.br().x && p.y >= r.tl().y && p.y <= r.br().y);
}

inline bool inRange(int i, int min_i, int max_i)
{
    return (i >= min_i && i <= max_i);
}

bool rectangleIntersect(const Rect &r1, const Rect &r2)
{
    // Check 1 -- Any corner inside rect
    if ((pointInRect(r1.tl(), r2) || pointInRect(r1.br(), r2)) || (pointInRect(r1.tr(), r2) || pointInRect(r1.bl(), r2)))
        return true;

    // Check 2 -- Overlapped, but all points outside
    //     +---+
    //  +--+---+----+
    //  |  |   |    |
    //  +--+---+----+
    //     +---+
    if ((inRange(r1.tl().x, r2.tl().x, r2.br().x) || inRange(r1.br().x, r2.tl().x, r2.br().x)) && r1.tl().y < r2.tl().y && r1.br().y > r2.br().y || (inRange(r1.tl().y, r2.tl().y, r2.br().y) || inRange(r1.br().y, r2.tl().y, r2.br().y)) && r1.tl().x < r2.tl().x && r1.br().x > r2.br().x)
        return true;

    return false;
}

class RadarDisplay
{
public:
    const int DEFAULT_WIDTH = 800;
    const int DEFAULT_HEIGHT = 600;
    RadarDisplay();
    ~RadarDisplay();

    Display *getDisplay();

    void drawRect(unsigned long col, int x, int y, int width, int height) const;
    void redraw();

private:
    Display *display_;
    int screen_;
    Window window_;
};

RadarDisplay::RadarDisplay()
{
    display_ = XOpenDisplay(NULL);
    if (display_ == NULL)
    {
        throw std::runtime_error("Unable to open the display");
    }

    screen_ = DefaultScreen(display_);

    window_ = XCreateSimpleWindow(display_, RootWindow(display_, screen_), 0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT, 1,
                                  BlackPixel(display_, screen_), 0x363d4d); // WhitePixel(display_,screen_));

    XSelectInput(display_, window_, KeyPressMask | ExposureMask);
    XMapWindow(display_, window_);
}

RadarDisplay::~RadarDisplay()
{
    XCloseDisplay(display_);
}

Display *RadarDisplay::getDisplay()
{
    return display_;
}

void RadarDisplay::drawRect(unsigned long col, int x, int y, int width, int height) const
{
    XSetForeground(display_, DefaultGC(display_, screen_), col);
    XFillRectangle(display_, window_, DefaultGC(display_, screen_), x, y, width, height);
    XFillRectangle(display_, window_, DefaultGC(display_, screen_), x + 5, y + 5, width, height);
}

void RadarDisplay::redraw()
{
    XClearWindow(display_, window_);

    Window root_wind;
    int x, y;
    unsigned int width, height, border_width, depth;
    XGetGeometry(display_, window_, &root_wind, &x, &y, &width,
                 &height, &border_width, &depth);

    XEvent ev;
    ev.xexpose.type = Expose;
    ev.xexpose.display = display_;
    ev.xexpose.window = window_;
    ev.xexpose.x = x;
    ev.xexpose.y = y;
    ev.xexpose.width = width;
    ev.xexpose.height = height;
    ev.xexpose.count = 0;

    XSendEvent(display_, window_, false, ExposureMask, &ev);
}

struct Aircraft
{
    unsigned long color = 0x6091ab;
    Point position{10, 10};
    Size size{10, 10};

    Aircraft(unsigned long new_col, Point new_pos, Size new_sz)
        : color(new_col), position(new_pos), size(new_sz){};

    Rect bounds() const
    {
        return {position.x, position.y, size.width, size.height};
    }
};

struct Jet : public Aircraft
{
    Jet() : Aircraft(0xff0000, {100, 100}, {10, 10})
    {
        time_at_last_move_ns_ = time_.time();
    };

    void move()
    {
        int direction = std::rand() % 4;
        const int MOVE_DIST = 10;

        switch (direction)
        {
        case 0:
            position.y -= MOVE_DIST;
            break;
        case 1:
            position.y += MOVE_DIST;
            break;
        case 2:
            position.x -= MOVE_DIST;
            break;
        case 3:
            position.x += MOVE_DIST;
            break;
        }

        time_at_last_move_ns_ = time_.time();
    }

    bool isTimeToMove()
    {
        return ((time_.time() - time_at_last_move_ns_) >= move_time_ns_);
    }

    long time_at_last_move_ns_;
    long move_time_ns_{250'000'000};
    _Time time_;
};

class AirSpace
{
public:
    AirSpace();
    ~AirSpace();

    bool updateGhosts();
    void createGhosts();

    void test();

private:
    std::vector<Jet> jet_;
    bool update_flag_;
    friend class Radar;
};

AirSpace::AirSpace()
{
    createGhosts();
}

AirSpace::~AirSpace()
{
}

bool AirSpace::updateGhosts()
{
    update_flag_ = false;
    for (auto &g : jet_)
    {
        if (g.isTimeToMove())
        {
            g.move();
            update_flag_ = true;

            return 1;
        }
    }
    return 0;
}

void AirSpace::createGhosts()
{
    jet_.clear();
    jet_.resize(10);
    const int MAXX = 800;
    const int MAXY = 600;

    for (auto &g : jet_)
    {
        g.position.x = (std::rand() % MAXX) / 10 * 10;
        g.position.y = (std::rand() % MAXY) / 10 * 10;
    }
}

void AirSpace::test()
{
    if (update_flag_)
        std::cout << update_flag_ << std::endl;
}

class Radar
{
public:
    Radar(AirSpace &air_space);

    void run();

private:
    RadarDisplay gamedisplay_;
    XEvent event_;
    bool is_running_ = true;
    bool game_over = false;
    bool game_won = false;

    std::vector<Jet> ghosts_;
    AirSpace *airspace_;

    bool getEvent();
    void updateGhosts();
    void handleEvent();
    void draw();
    void createGhosts();
    void drawAllGhosts();
    void update();
    void drawCharacter(const Aircraft &obj) const;
};

Radar::Radar(AirSpace &air_space)
{
    airspace_ = &air_space;
    std::srand(std::time(nullptr));
    createGhosts();
}

void Radar::run()
{
    airspace_->updateGhosts();

    if (airspace_->update_flag_)
        gamedisplay_.redraw();

    if (is_running_)
    {

        if (!game_over)
            updateGhosts();

        if (getEvent())
        {
            handleEvent();
        }
    }
}

bool Radar::getEvent()
{
    if (XPending(gamedisplay_.getDisplay()))
    {
        XNextEvent(gamedisplay_.getDisplay(), &event_);
        // printf("EVENT: %d\n", event_.type);
        return true;
    }

    return false;
}

void Radar::draw()
{
    drawAllGhosts();
}

void Radar::createGhosts()
{
    ghosts_.clear();
    ghosts_.resize(50);
    const int MAXX = 800;
    const int MAXY = 600;

    for (auto &g : ghosts_)
    {
        g.position.x = (std::rand() % MAXX) / 10 * 10;
        g.position.y = (std::rand() % MAXY) / 10 * 10;
    }
}

void Radar::drawAllGhosts()
{
    for (auto &g : airspace_->jet_)
    {
        drawCharacter(g);
    }
}

void Radar::drawCharacter(const Aircraft &obj) const
{
    gamedisplay_.drawRect(obj.color,
                          obj.position.x,
                          obj.position.y,
                          obj.size.width,
                          obj.size.height);
}

void Radar::updateGhosts()
{
}

void Radar::handleEvent()
{
    if (event_.type == Expose)
    {
        draw();
    }
}
