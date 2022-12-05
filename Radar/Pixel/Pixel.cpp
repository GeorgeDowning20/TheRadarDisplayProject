//---------------------------------------------------------------------------//
/// @file Pixel.cpp
/// @brief This file contains the function for the class Pixel
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the function for the class Pixel. This class represents a single pixel and contains all the information required to represent a pixel. This includes the x and y coordinates and the brightness of the pixel. This class also contains functions to show the details of the pixel. This class is used by the icon class to represent the pixels in an icon.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                           Preprocessor Directives
//---------------------------------------------------------------------------//

#include "Pixel.h" // Pixel.h

//---------------------------------------------------------------------------//
//                           Function Definitions
//---------------------------------------------------------------------------//

/// @details This is the default constructor for the pixel class. It sets the x and y coordinates to 0 and the brightness to 0.
/// @par Example:
/// @include main1.cpp
pixel::pixel()
{
    x = 0, y = 0, Brightness = 0;
}; // Default constructor

/// @details This is the default deconstructor for the pixel class.
pixel::~pixel() = default;

/// @details This is the default constructor for the pixel class. It sets the x and y coordinates to the values passed in and the brightness to the value passed in.
/// @par Example:
/// @include main2.cpp
pixel::pixel(float x, float y, uint8_t Brightness) : x(x),
                                                     y(y), Brightness(Brightness){}; // Constructor with x, y and Brightness

/// @details This is the default constructor for the pixel class. It sets the x and y coordinates to the values passed in and the brightness to 0.
pixel::pixel(float x, float y) : x(x), y(y) { Brightness = 0; }; // Constructor with x and y

/// @details This function returns the x , y coordinates and brightness of the pixel. It is used for debugging purposes.
/// @note Static declaration is used to indicate that this function is not associated with a specific instance of the class.
/// @par Example:
/// @include main3.cpp
enum status_e pixel::showPixelDetail(pixel const &pixel)
{
    std::cout << "Pixel at (" << pixel.x                                // Show the x coordinate
              << ", " << pixel.y                                        // Show the y coordinate
              << ") has a brightness of " << unsigned(pixel.Brightness) // Show the brightness
              << std::endl;                                             // End the line

    return STATUS_OK;
}

/// @details This function returns the x , y coordinates and brightness of the pixel.
/// @note This function is a wrapper for the #showPixelDetail function to allow it to be called on a pixel object.
enum status_e pixel::showPixelDetail()
{
    return pixel::showPixelDetail(*this); // Call the static function with the current object
}

/// @details This function returns the x , y coordinates and brightness of the pixel. It is used for debugging purposes.
/// @note Static declaration is used to indicate that this function is not associated with a specific instance of the class.
/// @note This function is a wrapper for #showPixelDetail because 'showPixelDetail' is a silly name for a function but is required by the specification.
enum status_e pixel::showDetail(pixel const &pixel)
{
    return pixel::showPixelDetail(pixel); // Call the static function with the current object
}

/// @details This function returns the x , y coordinates and brightness of the pixel. It is used for debugging purposes.
/// @note This function is a wrapper for #showPixelDetail because 'showPixelDetail' is a silly name for a function but is required by the specification.
enum status_e pixel::showDetail()
{
    return pixel::showPixelDetail(*this); // Call the static function with the current object
}

/// @details This function returns the x coordinate of the pixel.
float pixel::getX() const
{
    return x; // Return the x coordinate
}

/// @details This function returns the y coordinate of the pixel.
float pixel::getY() const
{
    return y; // Return the y coordinate
}

/// @details This function returns the brightness of the pixel.
uint8_t pixel::getBrightness() const
{
    return Brightness; // Return the brightness
}

/// @details This function sets the x coordinate of the pixel. It returns STATUS_OK if the x coordinate is valid.
enum status_e pixel::setX(float x)
{
    this->x = x;      // Set the x coordinate to the value passed in
    return STATUS_OK; // Return STATUS_OK
}

/// @details This function sets the y coordinate of the pixel. It returns STATUS_OK if the y coordinate is valid.
enum status_e pixel::setY(float y)
{
    this->y = y;      // Set the y coordinate to the value passed in
    return STATUS_OK; // Return STATUS_OK
}

/// @details This function sets the brightness of the pixel. It returns STATUS_OK if the brightness is valid.
enum status_e pixel::setBrightness(uint8_t Brightness)
{
    this->Brightness = Brightness; // Set the brightness to the value passed in
    return STATUS_OK;              // Return STATUS_OK
}
