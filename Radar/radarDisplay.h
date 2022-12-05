//---------------------------------------------------------------------------//
/// @file radarDisplay.cpp
/// @brief This file contains the radarDisplay class Declaration
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This files contains the radarDisplay class. the radarDisplay class is used to create a radar display object. The radar display object is used to display the airspace to the on a display.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//
#pragma once // Include guard

#include <X11/Xlib.h> // X11/Xlib.h
#include <vector>     // vector

#include "Airspace/Airspace.h"       // Airspace.h
#include "RadarScreen/RadarScreen.h" // RadarScreen.h

//---------------------------------------------------------------------------//
//                           Class Declaration
//---------------------------------------------------------------------------//

/// @brief radarDisplay class
/// @details This is the radarDisplay class. The radarDisplay class is used to create a radar display object. the radarDisplay class contains a function to initialise the radar display as a default radar display. And a function to run the radar display.
/// @date 2020-11-24
/// @author G.Downing
class radarDisplay
{
public:
    /// @brief initialise the radar display
    /// @param air_space the airspace to be displayed on the radar display
    radarDisplay(Air_Space &air_space);

    /// @brief run the radar display
    void run();

private:
    Radar_Screen RadarDisplay_; ///< The radar screen instance to be used to display the airspace on the radar display
    XEvent event_;              ///< The XEvent instance used to handle events
    bool is_running_ = true;    ///< The bool instance used to determine if the radar display is running
    bool STOP = false;          ///< The bool instance used to determine if the radar display should stop

    Air_Space *airspace_; ///< The Air_Space instance used to store the airspace to be displayed on the radar display

    /// @brief handle the events
    bool _get_Event();

    /// @brief handle the starting conditions
    void _handle_Event();

    /// @brief Display all aircraft in the airspace on the radar display window
    void _Draw_All_Aircraft();
};
