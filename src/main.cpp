//---------------------------------------------------------------------------//
/// @file main.cpp
/// @brief This file contains the main function
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the main function for the program
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
/// @details Doxygen Documentation for file: https://georgedowning20.github.io/TheRadarDisplayProject/main_8cpp.html
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

int main()
{

    AirSpace Lasham(5, 6, 7);
    AirSpace test(5, 6, 7);

    Radar g(Lasham);
    Radar q(test);

    while (1)
    {
        g.run();
        q.run();
    }
    return 0;
}

/// @brief Main program
/// @param[out] printf Any relevant error messages
/// @param[out] printf Icon Details
/// @details description of the function
/// @author G.Downing
/// @date 2020-11-24
// int main()
// {
//     icon myIcon;

//     pixel pixelOne(2.4, 1.2, 12);

//     pixel test = pixel(1.2, 2.4, 12);

//     if (myIcon.setPixel(0, pixelOne) != STATUS_OK)
//     {
//         std::cout << "Error setting pixel" << std::endl;
//         return STATUS_ERROR;
//     }

//     if (myIcon.showDetails() != STATUS_OK)
//     {
//         std::cout << "Error showing details" << std::endl;
//         return STATUS_ERROR;
//     }

//     if (myIcon.initialiseAsDefaultDiagonalLine(15) != STATUS_OK)
//     {
//         std::cout << "Error creating diagonal icon" << std::endl;
//         return STATUS_ERROR;
//     }

//     if (myIcon.showDetails() != STATUS_OK)
//     {
//         std::cout << "Error showing details" << std::endl;
//         return STATUS_ERROR;
//     }
// }
