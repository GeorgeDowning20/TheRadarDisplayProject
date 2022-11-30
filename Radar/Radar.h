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
    RadarDisplay RadarDisplay_;
    XEvent event_;
    bool is_running_ = true;
    bool STOP = false;

    AirSpace *airspace_;

    bool getEvent();
    void handleEvent();
    void drawAllGhosts();
    void update();
};
