#include <X11/Xlib.h>
#include <vector>

#include "Airspace/Airspace.h"
#include "RadarScreen/RadarScreen.h"

class radarDisplay
{
public:
    radarDisplay(AirSpace &air_space);

    void run();

private:
    RadarScreen RadarDisplay_;
    XEvent event_;
    bool is_running_ = true;
    bool STOP = false;

    AirSpace *airspace_;

    bool getEvent();
    void handleEvent();
    void DrawAllAircraft();
    void update();
};
