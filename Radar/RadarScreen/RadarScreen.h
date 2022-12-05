#pragma once

#include <X11/Xlib.h>
#include <iostream>

#include "../Aircraft/Aircraft.h"
class Radar_Screen
{
public:
    const int DEFAULT_WIDTH = 800;
    const int DEFAULT_HEIGHT = 600;
    Radar_Screen();
    ~Radar_Screen();
    void Draw_Aircraft(const Aircraft &obj);

    Display *get_Display() const;

    void draw_Rect(unsigned long col, int x, int y, int width, int height) const;
    void re_draw();

private:
    Display *display_;
    int screen_;
    Window window_;
};