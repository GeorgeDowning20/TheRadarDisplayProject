//---------------------------------------------------------------------------//
/// @file Pixel.h
/// @brief This file contains the class declaration for the pixel class
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the class declaration for the pixel class and function prototypes. this class represents a pixel on the radar display and contains the x and y coordinates and the colour of the pixel as well as functions to show the details of the pixel. This class is used by the icon class to represent the pixels in an icon. This class is also used by the radar class to represent the pixels on the radar display. This class is also used by the radarDisplay class to represent the pixels on the radar display. This class is also used by the radarDisplay class to represent the pixels on the radar display.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                           Preprocessor Directives
//---------------------------------------------------------------------------//

#pragma once // Include guard

#include "../../src/main.h" // main.h
#include <cstdint>          // uint8_t
#include <iostream>         // std::cout
#include <algorithm>        // std::min

//---------------------------------------------------------------------------//
//                           Class Declaration
//---------------------------------------------------------------------------//

/// @brief This class represents a single pixel
/// @details This class represents a single pixel and contains all the information required to represent a pixel. This includes the x and y coordinates and the brightness of the pixel. This class also contains functions to show the details of the pixel. This class is used by the icon class to represent the pixels in an icon.
/// @author G.Downing
/// @date 2020-11-24
class pixel
{
private:
    float x;            ///< The x coordinate of the pixel
    float y;            ///< The y coordinate of the pixel
    uint8_t Brightness; ///< The brightness of the pixel

public:
    /// @brief Default constructor for pixel
    pixel();

    /// @brief Default deconstructor for pixel
    ~pixel();

    /// @brief Default constructor for pixel with x, y and Brightness
    /// @param[in,out] x The x coordinate of the pixel
    /// @param[in,out] y The y coordinate of the pixel
    /// @param Brightness The brightness of the pixel (0-20)
    pixel(float x, float y, uint8_t Brightness);

    /// @brief Default constructor with brightness set to 0
    /// @param[in,out] x The x coordinate of the pixel
    /// @param[in,out] y The y coordinate of the pixel
    pixel(float x, float y);

    /// @brief Show the x coordinate of the pixel
    /// @return The x coordinate of the pixel
    float get_X() const;

    /// @brief  Show the y coordinate of the pixel
    /// @return The y coordinate of the pixel
    float get_Y() const;

    /// @brief Show the brightness of the pixel
    /// @return The brightness of the pixel
    uint8_t get_Brightness() const;

    /// @brief Set the x coordinate of the pixel
    /// @param[in,out] x The x coordinate of the pixel
    enum status_e set_X(float x);

    /// @brief Set the y coordinate of the pixel
    /// @param[in,out] y The y coordinate of the pixel
    enum status_e set_Y(float y);

    /// @brief Set the brightness of the pixel
    /// @param[in,out] brightness The brightness of the pixel (0-20)
    enum status_e set_Brightness(uint8_t brightness);

    /// @brief Show the details of the pixel
    /// @return STATUS_OK
    enum status_e showPixelDetail();

    /// @brief Show the details of the pixel
    /// @param[in] pixel The pixel to show the details of
    /// @return STATUS_OK
    static enum status_e showPixelDetail(pixel const &pixel);

    /// @brief Show the details of the pixel
    /// @return STATUS_OK
    enum status_e show_Detail();

    /// @brief Show the details of the pixel
    /// @param[in] pixel The pixel to show the details of
    /// @return STATUS_OK
    static enum status_e show_Detail(pixel const &pixel);
};
