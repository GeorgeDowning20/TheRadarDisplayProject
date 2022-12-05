//---------------------------------------------------------------------------//
/// @file main4.cpp
/// @brief This file contains a main function to test the fourth and fifth subtasks of the project
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This files contains the main function to test the fourth and fifth subtasks of the project. the main function creates and instance of an icon and pixel. the pixel is initiated with some test data and then added to the icon. the icon is then printed to the console.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//

#include "../Radar/Pixel/Pixel.cpp" // Pixel.cpp
#include "../Radar/Icon/Icon.cpp"   // Icon.cpp

//---------------------------------------------------------------------------//
//                           Main Program
//---------------------------------------------------------------------------//

/// @brief main program
/// @return 0
/// @details This is the main function for the program. an icon is created named myIcon. a pixel is created named myPixel, where the x and y coordinates to 1 and 2 and its brightness to 3. the pixel is then added to the icon.
/// @note no output is expected from this program.
/// @test This program compiles successfully.
/// @date 2020-11-24
/// @author G.Downing
int main()
{
    icon myIcon;             // Create an icon object
    pixel pixelOne(1, 2, 3); // Create a pixel object with the specified input data: x and y coordinates to 1 and 2 and its brightness to 3.

    if (myIcon.setPixel(0, pixelOne) != STATUS_OK) // If the pixel is not set successfully
    {
        std::cout << "Error: Pixel not set successfully" << std::endl; // Print an error message
    }
    return 0; // Return 0
}
