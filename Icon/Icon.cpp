#include "Icon.h"

icon::icon() = default;                                   // This is the default constructor
icon::icon(uint8_t Id) : Id(Id){};                        // This is the constructor with one parameter
icon::icon(uint8_t __Id, pixel __The_Pixels[]) : Id(__Id) // This is the constructor with two parameters
{
    for (int i = 0; i < 16; i++) // loop through the pixels
    {
        The_Pixels[i] = __The_Pixels[i]; // copy the pixels from the array passed in to the array in the class
    }
}
icon::icon(pixel __The_Pixels[])
{
    for (int i = 0; i < 16; i++)
    {
        The_Pixels[i] = __The_Pixels[i];
    }
};

pixel icon::getPixel(uint8_t pixelId)
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
