//---------------------------------------------------------------------------//
/// @file main.cpp
/// @brief This file contains the main function
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the main function for the program
/// @details Doxygen Documentation: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

#include <iostream>
#include <cstdint>
#include "main.h"
#include "../Pixel/Pixel.h"
#include "../Pixel/Pixel.cpp"
#include "../Icon/Icon.h"
#include "../Icon/Icon.cpp"

//---------------------------------------------------------------------------//
//                           Main Program
//---------------------------------------------------------------------------//

/// @brief Main program
/// @param[out] printf Any relevant error messages
/// @param printf Icon Details
/// @details description of the function
/// @author G.Downing
/// @date 2020-11-24
int main()
{
    icon myIcon;

    pixel pixelOne(2.4, 1.2, 12);

    pixel test = pixel(1.2, 2.4, 12);

    if (myIcon.setPixel(0, pixelOne) != STATUS_OK)
    {
        std::cout << "Error setting pixel" << std::endl;
        return STATUS_ERROR;
    }

    if (myIcon.showDetails() != STATUS_OK)
    {
        std::cout << "Error showing details" << std::endl;
        return STATUS_ERROR;
    }

    if (myIcon.initialiseAsDefaultDiagonalLine(15) != STATUS_OK)
    {
        std::cout << "Error creating diagonal icon" << std::endl;
        return STATUS_ERROR;
    }

    if (myIcon.showDetails() != STATUS_OK)
    {
        std::cout << "Error showing details" << std::endl;
        return STATUS_ERROR;
    }
}
