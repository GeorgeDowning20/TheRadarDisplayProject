#include <X11/Xlib.h>
#include <vector>

#include "Airspace/Airspace.h"
#include "RadarDisplay/RadarDisplay.h"

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
