#pragma once

#include <cstdint>
#include <iostream>
#include "../../src/main.h"
#include "../Pixel/Pixel.h"

class icon
{
private:
    pixel The_Pixels[16];
    uint8_t Id;

public:
    icon();

    icon(uint8_t Id);

    icon(uint8_t __Id, pixel __The_Pixels[]);

    icon(pixel __The_Pixels[]);

    pixel getPixel(uint8_t pixelId) const;
    uint8_t getId();

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
