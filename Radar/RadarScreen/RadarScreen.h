//---------------------------------------------------------------------------//
/// @file radarScreen.h
/// @brief This file contains the radarScreen class Deceleration
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the radarScreen class Deceleration. This class is used to create the radar screen and display the radar screen on the screen.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//
#pragma once // Include guard

#include <X11/Xlib.h> // X11/Xlib.h
#include <iostream>   // std::cout

#include "../Aircraft/Aircraft.h" // Aircraft.h

//---------------------------------------------------------------------------//
//                           Class Deceleration
//---------------------------------------------------------------------------//

/// @brief radarScreen class
/// @details This is the radarScreen class. The radarScreen class is used to create the radar screen and display the radar screen on the screen.
/// @date 2020-11-24
/// @author G.Downing
class Radar_Screen
{
public:
    const int DEFAULT_WIDTH = 800;  ///< The int instance used to store the default width of the radar screen
    const int DEFAULT_HEIGHT = 600; ///< The int instance used to store the default height of the radar screen

    /// @brief constructor the radar screen
    Radar_Screen();

    /// @brief deconstructor the radar screen
    ~Radar_Screen();

private:
    /// @brief draw a line to represent a pixel and interface with x11 library
    void _re_draw();

    /// @brief Draw the icon of the aircraft in the designated place
    /// @param aircraft the aircraft to be drawn
    void _Draw_Aircraft(const Aircraft &obj);

    /// @brief return display instance
    Display *_get_Display() const;

    Display *display_; ///< The Display instance used to store the display
    int screen_;       ///< The int instance used to store the screen
    Window window_;    ///< The Window instance used to store the window

    friend class radarDisplay;
};