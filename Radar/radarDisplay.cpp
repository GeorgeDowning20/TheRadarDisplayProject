//---------------------------------------------------------------------------//
/// @file radarDisplay.cpp
/// @brief This file contains the radarDisplay class Definition
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This files contains the radarDisplay class. the radarDisplay class is used to create a radar display object. The radar display object is used to display the airspace to the on a display.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//
#include "radarDisplay.h"

//---------------------------------------------------------------------------//
//                           Class Definition
//---------------------------------------------------------------------------//

/// @details This is the constructor for the radarDisplay class. The constructor initialises the radarDisplay object with the given airspace that it should be displaying.
radarDisplay::radarDisplay(Air_Space &air_space)
{
    airspace_ = &air_space;         // Set the airspace_ pointer to the given airspace
    std::srand(std::time(nullptr)); // Seed the random number generator
}

/// @details This is the run function for the radarDisplay class. The run function is used to run the radar display. The run function is used to handle the events and display the aircraft in the airspace on the radar display.
void radarDisplay::run()
{
    airspace_->_update_Aircraft(); // Update the aircraft in the airspace

    if (airspace_->update_flag_)  // If the airspace has been updated
        RadarDisplay_._re_draw(); // Redraw the radar display

    if (is_running_) // if the radar display is running
    {

        if (!STOP)            // If the radar display is not stopped
            if (_get_Event()) // Get the event
            {
                _handle_Event(); // Handle the event
            }
    }
}

/// @details This is the _get_Event function for the radarDisplay class. The _get_Event function is used to get the events from the radar display. The _get_Event function is used to get the events from the radar display and return a bool to determine if the radar display should continue running.
bool radarDisplay::_get_Event()
{
    if (XPending(RadarDisplay_._get_Display())) // If there is an event
    {
        XNextEvent(RadarDisplay_._get_Display(), &event_); // Get the event
        return true;                                       // Return true
    }

    return false; // Return false
}

/// @details This is the _handle_Event function for the radarDisplay class. The _handle_Event function is used to handle the events from the radar display. This is responsible for drawing the aircraft on the radar display.
void radarDisplay::_Draw_All_Aircraft()
{
    for (auto &g : airspace_->Jet) // For each jet in the airspace
    {
        RadarDisplay_._Draw_Aircraft(g); // Draw the aircraft
    }

    for (auto &g : airspace_->Heli) // For each Heli in the airspace
    {
        RadarDisplay_._Draw_Aircraft(g); // Draw the aircraft
    }

    for (auto &g : airspace_->Plane) // For each Plane in the airspace
    {
        RadarDisplay_._Draw_Aircraft(g); // Draw the aircraft
    }
}

/// @details This is the _handle_Event function for the radarDisplay class. The _handle_Event function is used to handle the events from the radar display and determine what action to take.
void radarDisplay::_handle_Event()
{
    if (event_.type == Expose) // If the event is an expose event
    {
        _Draw_All_Aircraft(); // Draw all the aircraft in the airspace
    }
}
