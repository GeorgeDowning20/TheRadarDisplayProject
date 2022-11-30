#include <X11/Xlib.h>
#include <iostream>

#include "../Aircraft/Aircraft.h"
class RadarDisplay
{
public:
    const int DEFAULT_WIDTH = 800;
    const int DEFAULT_HEIGHT = 600;
    RadarDisplay();
    ~RadarDisplay();
    void DrawAircraft(const Aircraft &obj);

    Display *getDisplay() const;

    void drawRect(unsigned long col, int x, int y, int width, int height) const;
    void redraw();

private:
    Display *display_;
    int screen_;
    Window window_;
};