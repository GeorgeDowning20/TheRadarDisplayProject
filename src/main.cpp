//---------------------------------------------------------------------------//
/// @file main.cpp
/// @brief This file contains the main function
/// @note This program was written to be compiled with cmake to create a linux application. The program can be compiled and run by executing the Build_and_run.sh script from build/.
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the main function for the program.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

#include "main.h"                  // main.h
#include <iostream>                // std::cout
#include <cstdint>                 // uint8_t
#include "../Radar/Pixel/Pixel.h"  // Pixel.h
#include "../Radar/Icon/Icon.h"    // Icon.h
#include "../Radar/radarDisplay.h" // Display.h
//---------------------------------------------------------------------------//
//                           Main Program
//---------------------------------------------------------------------------//

/// @brief main program
/// @return 0
/// @details This is the main function for the program. two instances of airspace are created and the airspace is populated with aircraft. The airspace is then displayed to the console. Three radar displays are created and the airspace is displayed on each radar display. two of the radars display the same airspace. The third radar displays a different airspace.
/// @date 2020-11-24
/// @author G.Downing
int main()
{
    Air_Space DAVENTRY_CTA(5, 6, 7); // Create an instance of airspace in this case it represents the airspace of the Daventry CTA (Controlled Airspace) over the midlands in the UK
    Air_Space LTMA(5, 6, 7);         // Create an instance of airspace in this case it represents the airspace of the London Terminal Manoeuvring Area (Controlled Airspace) London in the UK

    radarDisplay East_Midlands_Tower(DAVENTRY_CTA); // Create a radar display for the East Midlands tower which is located below Daventry CTA
    radarDisplay Birmingham_Approach(DAVENTRY_CTA); // Create a radar display for Birmingham Approach which is located in the same airspace as East Midlands Tower
    radarDisplay Luton_Radar(LTMA);                 // Create a radar display for Luton Radar which is located below the London Terminal Manoeuvring Area

    while (1) // runtime
    {
        East_Midlands_Tower.run(); // Run the radar display
        Birmingham_Approach.run(); // Run the radar display
        Luton_Radar.run();         // Run the radar display
    }
    return 0; // Return 0
}
