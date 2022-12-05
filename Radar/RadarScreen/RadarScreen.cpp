#include "RadarScreen.h"

RadarScreen::RadarScreen()
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

RadarScreen::~RadarScreen()
{
    XCloseDisplay(display_);
}

Display *RadarScreen::getDisplay() const
{
    return display_;
}

void RadarScreen::drawRect(unsigned long col, int x, int y, int width, int height) const
{
    XSetForeground(display_, DefaultGC(display_, screen_), col);
    XFillRectangle(display_, window_, DefaultGC(display_, screen_), x, y, width, height);
    XFillRectangle(display_, window_, DefaultGC(display_, screen_), x + 5, y + 5, width, height);
}

void RadarScreen::DrawAircraft(const Aircraft &obj)
{
    XSetForeground(display_, DefaultGC(display_, screen_), obj.color);
    for (int i = 0; i < 16; i++)
    {
        XFillRectangle(display_, window_, DefaultGC(display_, screen_), obj.position.x + (obj.icon_.getPixel(i).getX() * obj.size.width), obj.position.y + (obj.icon_.getPixel(i).getY() * obj.size.height), obj.size.width, obj.size.height);
    }
}

void RadarScreen::redraw()
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