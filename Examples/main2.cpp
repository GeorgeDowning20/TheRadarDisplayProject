//---------------------------------------------------------------------------//
/// @file main2.cpp
/// @brief This file contains a main function to test the second subtask of the project
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains a main function to test the second subtask of the project. the main functions creates an instance of a pixel with the specified input data. the characteristics of the pixel are then printed to the console.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
/// @par Code:
/// @include main2.cpp
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//

#include "../Radar/Pixel/Pixel.cpp" // Pixel.cpp

//---------------------------------------------------------------------------//
//                           Main Program
//---------------------------------------------------------------------------//

/// @brief main program
/// @return 0
/// @details This is the main function for the program. a pixel is created named aPixel, where the x and y coordinates to 3.9 and 4.1 and its brightness to 7. the characteristics of the pixel are then printed to the console.
/// @test Output: "Pixel at (3.7, 4.1) has a brightness of 7"
/// @date 2020-11-24
/// @author G.Downing
int main()
{
    pixel aPixel(3.7, 4.1, 7); // Create a pixel object with the specified input data: x and y coordinates to 3.9 and 4.1 and its brightness to 7.

    std::cout << "Pixel at (" << aPixel.get_X()                                // Print the x coordinate of the pixel
              << ", " << aPixel.get_Y()                                        // Print the y coordinate of the pixel
              << ") has a brightness of " << unsigned(aPixel.get_Brightness()) // Print the brightness of the pixel
              << " \n " << std::endl;                                          // Print a new line
    return 0;
}
