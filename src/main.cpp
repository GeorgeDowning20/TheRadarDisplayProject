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

#include "main.h"                 // main.h
#include <iostream>               // std::cout
#include <cstdint>                // uint8_t
#include "../Radar/Pixel/Pixel.h" // Pixel.h
#include "../Radar/Icon/Icon.h"   // Icon.h
#include "../Radar/Radar.h"       // Display.h
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
    AirSpace DAVENTRY_CTA(5, 6, 7); // Create an instance of airspace
    AirSpace LTMA(5, 6, 7);         // Create an instance of airspace

    Radar a(DAVENTRY_CTA); // Create a radar display
    Radar b(DAVENTRY_CTA); // Create a radar display
    Radar c(LTMA);         // Create a radar display

    while (1) // runtime
    {
        a.run(); // Run the radar display
        b.run(); // Run the radar display
        c.run(); // Run the radar display
    }
    return 0; // Return 0
}
