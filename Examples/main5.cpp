//---------------------------------------------------------------------------//
/// @file main5.cpp
/// @brief This file contains a main function to test the sixth and seventh subtasks of the project
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This files contains the main function to test the sixth and seventh subtasks of the project. the main function creates and instance of an empty icon and then it is initialised as a diagonal line using the #initialiseAsDefaultDiagonalLine(uint8_t Brightness) function from the Icon class. the icon is then printed to the console using the #showIconDetail function from the Icon class.
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
/// @details This is the main function for the program. an icon is created named myIcon. the icon is then initialised as a diagonal line using the #icon::initialiseAsDefaultDiagonalLine(uint8_t Brightness) function from the Icon class. the icon is then printed to the console using the #icon::showIconDetail function from the Icon class.
/**  @test
Output: \n
Icon 0 has the following pixels: \n
Pixel at (0, 0) has a brightness of 15 \n
Pixel at (1, 1) has a brightness of 15 \n
Pixel at (2, 2) has a brightness of 15 \n
Pixel at (3, 3) has a brightness of 15 \n
Pixel at (4, 4) has a brightness of 15 \n
Pixel at (5, 5) has a brightness of 15 \n
Pixel at (6, 6) has a brightness of 15 \n
Pixel at (7, 7) has a brightness of 15 \n
Pixel at (8, 8) has a brightness of 15 \n
Pixel at (9, 9) has a brightness of 15 \n
Pixel at (10, 10) has a brightness of 15 \n
Pixel at (11, 11) has a brightness of 15 \n
Pixel at (12, 12) has a brightness of 15 \n
Pixel at (13, 13) has a brightness of 15 \n
Pixel at (14, 14) has a brightness of 15 \n
Pixel at (15, 15) has a brightness of 15
**/
/// @date 2020-11-24
/// @author G.Downing
int main()
{
    icon myIcon; // Create an icon object

    if (myIcon.initialiseAsDefaultDiagonalLine(15) != STATUS_OK) // If the icon is not initialised successfully
    {
        std::cout << "Error: Icon not initialised successfully" << std::endl; // Print an error message
        return STATUS_ERROR;
    }

    if (myIcon.showIconDetail() != STATUS_OK) // If the icon detail is not shown successfully
    {
        std::cout << "Error: Icon detail not shown successfully" << std::endl; // Print an error message
        return STATUS_ERROR;
    }
}