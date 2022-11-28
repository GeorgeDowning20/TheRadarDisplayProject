

#include "Pixel.h"

/// @details This is the default constructor for the pixel class. It sets the x and y coordinates to 0 and the brightness to 0.
pixel::pixel() { x = 0, y = 0, Brightness = 0; };

/// @details This is the default constructor for the pixel class. It sets the x and y coordinates to the values passed in and the brightness to the value passed in.
pixel::pixel(float x, float y, uint8_t Brightness) : x(x), y(y), Brightness(Brightness){};

/// @details This is the default constructor for the pixel class. It sets the x and y coordinates to the values passed in and the brightness to 0.
pixel::pixel(float x, float y) : x(x), y(y) { Brightness = 0; };

/// @details This function returns the x , y coordinates and brightness of the pixel. It is used for debugging purposes.
/// @note Static declaration is used to indicate that this function is not associated with a specific instance of the class.
enum status_e pixel::showPixelDetail(pixel const &pixel)
{
    std::cout << "Pixel at (" << pixel.x
              << ", " << pixel.y
              << ") has a brightness of " << unsigned(pixel.Brightness)
              << " \n " << std::endl;

    return STATUS_OK;
}

/// @details This function returns the x , y coordinates and brightness of the pixel.
/// @note This function is a wrapper for the showPixelDetail function to allow it to be called on a pixel object.
enum status_e pixel::showPixelDetail()
{
    return pixel::showPixelDetail(*this);
}

/// @details This function returns the x , y coordinates and brightness of the pixel. It is used for debugging purposes.
/// @note Static declaration is used to indicate that this function is not associated with a specific instance of the class.
/// @note This function is a wrapper for showPixelDetail because 'showPixelDetail' is a silly name for a function but is required by the specification.
enum status_e pixel::showDetail(pixel const &pixel)
{
    return pixel::showPixelDetail(pixel);
}

enum status_e pixel::showDetail()
{
    return pixel::showPixelDetail(*this);
}

float pixel::getX()
{
    return x;
}

float pixel::getY()
{
    return y;
}

uint8_t pixel::getBrightness()
{
    return Brightness;
}

void pixel::setX(float x)
{
    this->x = x;
}

void pixel::setY(float y)
{
    this->y = y;
}

void pixel::setBrightness(uint8_t Brightness)
{
    this->Brightness = Brightness;
}
