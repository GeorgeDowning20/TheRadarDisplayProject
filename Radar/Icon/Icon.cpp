//---------------------------------------------------------------------------//
/// @file Icon.cpp
/// @brief This file contains the declarations for the icon class
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the declarations for the icon class. The icon class is used to create an icon. The icon is used to represent an aircraft on the radar display.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        Preprocessor Directives
//---------------------------------------------------------------------------//
#include "Icon.h" // icon

//---------------------------------------------------------------------------//
//                           Class Definitions
//---------------------------------------------------------------------------//

/// @details This is the default constructor for the icon class. It is used to create an icon object.
/// @par Example:
/// @include main4.cpp
icon::icon()
{
    Id = 0;
};

/// @details This is the constructor for the icon class that takes an id. It is used to create an icon object.
icon::icon(uint8_t Id) : Id(Id){};

icon::~icon() = default;

/// @details This is the constructor for the icon class that takes an id and an array of pixels. It is used to create an icon object. The pixels are iterated through and added to the icon object.
/// @note This constructor is the best way to create an icon object.
icon::icon(uint8_t __Id, pixel __The_Pixels[]) : Id(__Id)
{
    for (int i = 0; i < 16; i++) // Iterate through the pixels
    {
        The_Pixels[i] = __The_Pixels[i]; // Add the pixel to the icon
    }
}

/// @brief This is the constructor for the icon class that takes in an array of pixels. It is used to create an icon object. The pixels are iterated through and added to the icon object.
icon::icon(pixel __The_Pixels[])
{
    for (int i = 0; i < 16; i++) // Iterate through the pixels
    {
        The_Pixels[i] = __The_Pixels[i]; // Add the pixel to the icon
    }
};

/// @details This function is used to get the pixel at the specified index.
pixel icon::get_Pixel(uint8_t pixelId) const
{
    return The_Pixels[pixelId]; // Return the pixel at the specified index
}

/// @details This function is used to get the id of the icon.
uint8_t icon::get_Id()
{
    return Id; // Return the id of the icon
}

/// @details This function prints the details of the icon to the console. This includes the id of the icon and the brightness of each pixel. This function is used for debugging.
enum status_e icon::show_Details(icon const &icon)
{
    std::cout << "Icon " << unsigned(icon.Id) << " has the following pixels:" << std::endl; // print the id of the icon UI message

    for (int i = 0; i < 16; i++) // Iterate through the pixels
    {
        pixel::show_Detail(icon.The_Pixels[i]); // Show the details of each pixel
    }
    return STATUS_OK; // Return status ok
};

/// @details This function prints the details of the icon to the console. This includes the id of the icon and the brightness of each pixel. This function is used for debugging.
/// @note This function is a wrapper for the show_Details function. It is used to make the code more portable.
enum status_e icon::show_Details()
{
    return icon::show_Details(*this); // Show the details of the icon object that called the function
};

/// @details This function prints the details of the icon to the console. This includes the id of the icon and the brightness of each pixel. This function is used for debugging.
/// @note This function is a wrapper for the show_Details function.
/// @note This function only exists because it is required by the specification however has a terrible name and should not be used.
/// @note use #show_Details(icon const &icon) instead.
enum status_e icon::showIconDetail(icon const &icon)
{
    return icon::show_Details(icon); // Return status ok
};

/// @details This function prints the details of the icon to the console. This includes the id of the icon and the brightness of each pixel. This function is used for debugging.
/// @note This function is a wrapper for the show_Details function.
/// @note This function only exists because it is required by the specification however has a terrible name and should not be used.
/// @note use show_Details() instead.
/// @par Example:
/// @include main5.cpp
enum status_e icon::showIconDetail()
{
    return icon::show_Details(*this); // Show the details of the icon object that called the function
};

/// @details This function is used to set a specific pixel in the icon. The pixel id is checked to see if the input is valid. if not an error status code is returned. If the input is valid the pixel is set. The status code is returned.
/// @par Example:
/// @include main4.cpp
enum status_e icon::set_Pixel(uint8_t pixelId, pixel const &pixel)
{
    if (pixelId > 15) // Check if the pixel id is greater than 15
    {
        return STATUS_ERROR; // Return status error
    }
    The_Pixels[pixelId] = pixel; // Set the pixel at the specified index
    return STATUS_OK;            // Return status ok
};

/// @details This function is used to set a specific pixel in the icon with out requiring an existing pixel object. The pixel id is checked to see if the input is valid. if not an error status code is returned. If the input is valid the pixel is set using x,y and brightness parameters. The status code is returned.
enum status_e icon::set_Pixel(uint8_t pixelId, float x, float y, uint8_t Brightness)
{
    if (pixelId > 15) // Check if the pixel id is greater than 15
    {
        return STATUS_ERROR; // Return status error
    }
    The_Pixels[pixelId].set_X(x);                   // Set the x coordinate of the pixel
    The_Pixels[pixelId].set_Y(y);                   // Set the y coordinate of the pixel
    The_Pixels[pixelId].set_Brightness(Brightness); // Set the brightness of the pixel
    return STATUS_OK;                               // Return status ok
};

/// @details This function is used to set every characteristic of the icon including ID and pixel array. The pixel id is set and then the pixel array is iterated through and set. The status code is returned.
enum status_e icon::set_Icon(uint8_t __Id, pixel __The_Pixels[])
{
    Id = __Id;                   // Set the id of the icon
    for (int i = 0; i < 16; i++) // iterate through the pixels
    {
        The_Pixels[i] = __The_Pixels[i]; // Set the pixels of the icon
    }
    return STATUS_OK; // Return status ok
};

/// @details This function is used to set pixel array. The pixel array is iterated through and set. The status code is returned.
enum status_e icon::update_Icon(pixel __The_Pixels[])
{
    for (int i = 0; i < 16; i++) // iterate through the pixels
    {
        The_Pixels[i] = __The_Pixels[i]; // Set the pixels of the icon
    }
    return STATUS_OK; // Return status ok
};

/// @details This function is used to set the icon to be a diagonal line. The pixel array is iterated through and set. The status code is returned.
/// @par Example:
/// @include main5.cpp
enum status_e icon::initialiseAsDefaultDiagonalLine(uint8_t Brightness)
{
    for (int pixelId = 0; pixelId < 16; pixelId++) // iterate through the pixels
    {
        The_Pixels[pixelId].set_X(pixelId + 1);         // Set the x coordinate of the pixel
        The_Pixels[pixelId].set_Y(pixelId + 1);         // Set the y coordinate of the pixel
        The_Pixels[pixelId].set_Brightness(Brightness); // Set the brightness of the pixel
    }
    return STATUS_OK; // Return status ok
};
