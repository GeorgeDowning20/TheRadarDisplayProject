#include <X11/Xlib.h>
#include <iostream>

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