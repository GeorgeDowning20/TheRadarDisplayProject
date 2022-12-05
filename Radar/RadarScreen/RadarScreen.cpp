//---------------------------------------------------------------------------//
/// @file radarScreen.cpp
/// @brief This file contains the radarScreen class Definitions
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the radarScreen class Definitions. This class is used to create the radar screen and display the radar screen on the screen.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//

#include "RadarScreen.h" // RadarScreen.h

//---------------------------------------------------------------------------//
//                           Class Definitions
//---------------------------------------------------------------------------//

/// @details this is the constructor for the radar screen class. it initialises a window to be used to display the radar screen
Radar_Screen::Radar_Screen()
{
    display_ = XOpenDisplay(NULL); // Open the display
    if (display_ == NULL)          // if the display is null
    {
        throw std::runtime_error("Unable to open the display"); // throw an error
    }

    screen_ = DefaultScreen(display_); // Get the screen

    window_ = XCreateSimpleWindow(display_, RootWindow(display_, screen_), 0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT, 1,
                                  BlackPixel(display_, screen_), 0x363d4d); // Create the window

    XSelectInput(display_, window_, KeyPressMask | ExposureMask); // Select the input
    XMapWindow(display_, window_);                                // Map the window
}

/// @details this is the deconstructor for the radar screen class. it closes the display
Radar_Screen::~Radar_Screen()
{
    XCloseDisplay(display_); // Close the display
}

/// @details this function used to return the instance of the display
Display *Radar_Screen::_get_Display() const
{
    return display_; // Return the display
}

/// @details this function is used to draw the aircraft on the radar screen. it takes in an aircraft object and draws the aircraft on the radar screen at the correct position by iterating through the pixels of the aircraft icon and drawing them on the radar screen
void Radar_Screen::_Draw_Aircraft(const Aircraft &obj)
{
    XSetForeground(display_, DefaultGC(display_, screen_), obj.color); // Set the foreground color
    for (int i = 0; i < 16; i++)                                       // for all pixels in the icon
    {
        XFillRectangle(display_, window_, DefaultGC(display_, screen_), obj.position.x + (obj.icon_.get_Pixel(i).get_X() * obj.size.width), obj.position.y + (obj.icon_.get_Pixel(i).get_Y() * obj.size.height), obj.size.width, obj.size.height); // Draw the pixel
    }
}

/// @details this function is used to redraw the radar screen.
void Radar_Screen::_re_draw()
{
    XClearWindow(display_, window_); // Clear the window

    Window root_wind;                                // The Window instance used to store the root window
    int x, y;                                        // The int instances used to store the x and y coordinates
    unsigned int width, height, border_width, depth; // The unsigned int instances used to store the width, height, border width, and depth
    XGetGeometry(display_, window_, &root_wind, &x, &y, &width,
                 &height, &border_width, &depth); // Get the geometry of the window

    XEvent ev;                     // The XEvent instance used to store the event
    ev.xexpose.type = Expose;      // Set the type of the event
    ev.xexpose.display = display_; // Set the display of the event
    ev.xexpose.window = window_;   // Set the window of the event
    ev.xexpose.x = x;              // Set the x coordinate of the event
    ev.xexpose.y = y;              // Set the y coordinate of the event
    ev.xexpose.width = width;      // Set the width of the event
    ev.xexpose.height = height;    // Set the height of the event
    ev.xexpose.count = 0;          // Set the count of the event

    XSendEvent(display_, window_, false, ExposureMask, &ev); // Send the event
}