//---------------------------------------------------------------------------//
/// @file Icon.cpp
/// @brief This file contains the definitions for the icon class
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the definitions for the icon class. The icon class is used to create an icon. The icon is used to represent an aircraft on the radar display.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        Preprocessor Directives
//---------------------------------------------------------------------------//
#include "Icon.h"

//---------------------------------------------------------------------------//
//                           Class Definitions
//---------------------------------------------------------------------------//

/// @details This is the default constructor for the icon class. It is used to create an icon object.
icon::icon() = default;

/// @details This is the constructor for the icon class that takes an id. It is used to create an icon object.
icon::icon(uint8_t Id) : Id(Id){};

icon::~icon() = default;

/// @details This is the constructor for the icon class that takes an id and an array of pixels. It is used to create an icon object. The pixels are iterated through and added to the icon object.
/// @note This constructor is the best way to create an icon object.
icon::icon(uint8_t __Id, pixel __The_Pixels[]) : Id(__Id)
{
    for (int i = 0; i < 16; i++)
    {
        The_Pixels[i] = __The_Pixels[i];
    }
}

/// @brief This is the constructor for the icon class that takes in an array of pixels. It is used to create an icon object. The pixels are iterated through and added to the icon object.
icon::icon(pixel __The_Pixels[])
{
    for (int i = 0; i < 16; i++)
    {
        The_Pixels[i] = __The_Pixels[i];
    }
};

/// @details This function is used to get the pixel at the specified index.
pixel icon::getPixel(uint8_t pixelId) const
{
    return The_Pixels[pixelId];
}

uint8_t icon::getId()
{
    return Id;
}

enum status_e icon::showIconDetail(icon const &icon)
{
    std::cout << "Icon " << unsigned(icon.Id) << " has the following pixels: " << std::endl;
    for (int i = 0; i < 16; i++)
    {
        pixel::showPixelDetail(icon.The_Pixels[i]);
    }
    return STATUS_OK;
};

enum status_e icon::showIconDetail()
{
    return icon::showIconDetail(*this);
};

enum status_e icon::showDetails(icon const &icon)
{
    std::cout << "Icon " << unsigned(icon.Id) << " has the following pixels: " << std::endl;
    for (int i = 0; i < 16; i++)
    {
        pixel::showDetail(icon.The_Pixels[i]);
    }
    return STATUS_OK;
};

enum status_e icon::showDetails()
{
    return icon::showDetails(*this);
};

enum status_e icon::setPixel(uint8_t pixelId, pixel const &pixel)
{
    if (pixelId > 15)
    {
        return STATUS_ERROR;
    }
    The_Pixels[pixelId] = pixel;
    return STATUS_OK;
};

enum status_e icon::setPixel(uint8_t pixelId, float x, float y, uint8_t Brightness)
{
    if (pixelId > 15)
    {
        return STATUS_ERROR;
    }
    The_Pixels[pixelId].setX(x);
    The_Pixels[pixelId].setY(y);
    The_Pixels[pixelId].setBrightness(Brightness);
    return STATUS_OK;
};

enum status_e icon::setIcon(uint8_t __Id, pixel __The_Pixels[])
{
    Id = __Id;
    for (int i = 0; i < 16; i++)
    {
        The_Pixels[i] = __The_Pixels[i];
    }
    return STATUS_OK;
};

enum status_e icon::updateIcon(pixel __The_Pixels[])
{
    for (int i = 0; i < 16; i++)
    {
        The_Pixels[i] = __The_Pixels[i];
    }
    return STATUS_OK;
};

enum status_e icon::initialiseAsDefaultDiagonalLine(uint8_t Brightness)
{
    for (int pixelId = 0; pixelId < 16; pixelId++)
    {
        The_Pixels[pixelId].setX(pixelId);
        The_Pixels[pixelId].setY(pixelId);
        The_Pixels[pixelId].setBrightness(Brightness);
    }
    return STATUS_OK;
};
