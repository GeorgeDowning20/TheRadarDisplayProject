//---------------------------------------------------------------------------//
/// @file Icon.h
/// @brief This file contains the class definition for the icon class
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the class definition for the icon class. The icon class is used to create an icon. The icon is used to represent an aircraft on the radar display. The icon is made up of pixels. The icon is displayed on the radar display. The icon can be moved around the radar display.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                           Preprocessor Directives
//---------------------------------------------------------------------------//
#pragma once

#include <cstdint>          // uint8_t
#include <iostream>         // std::cout
#include "../../src/main.h" // main.h
#include "../Pixel/Pixel.h" // pixel

//---------------------------------------------------------------------------//
//                           Class Declaration
//---------------------------------------------------------------------------//

/// @brief This class represents an icon
/// @details This class represents an icon and contains all the information required to represent an icon. This includes the x and y coordinates and the brightness of the icon. This class also contains functions to show the details of the icon. This class is used by the radar class to represent the icons on the radar display.
/// @author G.Downing
/// @date 2020-11-24

class icon
{
private:
    pixel The_Pixels[16]; ///< The pixels that make up the icon
    uint8_t Id;           ///< The id of the icon

public:
    /// @brief Default constructor for icon
    icon();

    /// @brief Default deconstructor for icon
    ~icon();

    /// @brief Constructor with id.
    /// @param Id The id of the icon
    icon(uint8_t Id);

    /// @brief Constructor with id and pixels
    /// @param __Id The id of the icon
    /// @param __The_Pixels Address of the array of pixels that make up the icon
    icon(uint8_t __Id, pixel __The_Pixels[]);

    /// @brief Constructor with pixels
    /// @param __The_Pixels Address of the array of pixels that make up the icon
    icon(pixel __The_Pixels[]);

    /// @brief Show the id of the icon
    /// @param pixelId The id of the icon
    /// @return The pixel at the specified index
    pixel getPixel(uint8_t pixelId) const;

    /// @brief Show the id of the icon
    /// @return The id of the icon
    uint8_t getId();

    /// @brief Set specific pixel in icon
    /// @param pixelId The id of the pixel to be changed
    /// @param pixel reference to the pixel to be set
    /// @return Status of the operation
    /// @arg STATUS_OK Success
    /// @arg STATUS_ERROR Failure
    enum status_e setPixel(uint8_t pixelId, pixel const &pixel);

    enum status_e setPixel(uint8_t pixelId, float x, float y, uint8_t Brightness);
    enum status_e setIcon(uint8_t __Id, pixel __The_Pixels[]);
    enum status_e updateIcon(pixel __The_Pixels[]);

    enum status_e initialiseAsDefaultDiagonalLine(uint8_t Brightness);

    static enum status_e showIconDetail(icon const &icon);
    enum status_e showIconDetail();

    static enum status_e showDetails(icon const &icon);
    enum status_e showDetails();
};
