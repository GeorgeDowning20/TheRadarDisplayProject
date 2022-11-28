#pragma once

#include <iostream>               // std::cout
#include <cstdint>                // uint8_t
#include "../Radar/Pixel/Pixel.h" // Pixel.h
#include "../Radar/Icon/Icon.h"   // Icon.h
#include "../Radar/Radar.h"       // Display.h

enum status_e
{
    STATUS_OK = 0,
    STATUS_ERROR = 1,
    STATUS_UNKNOWN = 2
};
