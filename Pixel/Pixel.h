#pragma once

/// @file Pixel.h
/// @brief This file contains declarations for the pixel class
/// @author G.Downing
/// @date 2020-11-24

#include "../src/main.h"
#include <cstdint>
#include <iostream>
#include <algorithm>

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

    /// @brief Default constructor for pixel with x, y and Brightness
    /// @param x The x coordinate of the pixel
    /// @param y The y coordinate of the pixel
    /// @param Brightness The brightness of the pixel (0-20)
    pixel(float x, float y, uint8_t Brightness);

    /// @brief Default constructor with brightness set to 0
    /// @param x The x coordinate of the pixel
    /// @param y The y coordinate of the pixel
    pixel(float x, float y);

    /// @brief Show the x coordinate of the pixel
    /// @return The x coordinate of the pixel
    float getX();

    /// @brief  Show the y coordinate of the pixel
    /// @return The y coordinate of the pixel
    float getY();

    /// @brief Show the brightness of the pixel
    /// @return The brightness of the pixel
    uint8_t getBrightness();

    /// @brief Set the x coordinate of the pixel
    /// @param x The x coordinate of the pixel
    void setX(float x);

    /// @brief Set the y coordinate of the pixel
    /// @param y The y coordinate of the pixel
    void setY(float y);

    /// @brief Set the brightness of the pixel
    /// @param Brightness The brightness of the pixel (0-20)
    void setBrightness(uint8_t brightness);

    /// @brief Show the details of the pixel
    /// @return STATUS_OK
    enum status_e showPixelDetail();

    /// @brief Show the details of the pixel
    /// @param pixel The pixel to show the details of
    /// @return STATUS_OK
    static enum status_e showPixelDetail(pixel const &pixel);

    /// @brief Show the details of the pixel
    /// @return STATUS_OK
    enum status_e showDetail();

    /// @brief Show the details of the pixel
    /// @param pixel The pixel to show the details of
    /// @return STATUS_OK
    static enum status_e showDetail(pixel const &pixel);
};
