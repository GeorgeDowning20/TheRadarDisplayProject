//---------------------------------------------------------------------------//
/// @file main1.cpp
/// @brief This file contains a main function to test the first subsection of the project
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains a main function to test the first subsection of the project. the main function creates a instance of a pixel which proves it compiles.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//

#include "../Radar/Pixel/Pixel.cpp" // Pixel.h

//---------------------------------------------------------------------------//
//                           Main Program
//---------------------------------------------------------------------------//

/// @brief main program
/// @return 0
/// @details This is the main function for the program. a pixel is created named myFirstPixel.
/// @note no output is expected from this program.
/// @test This program compiles successfully.
/// @date 2020-11-24
/// @author G.Downing
int main()
{
    pixel myFirstPixel; // Create a pixel object
    return 0;
}