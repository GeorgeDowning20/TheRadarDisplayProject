#include "../Radar/Pixel/Pixel.h"   // Pixel.h
#include "../Radar/Pixel/Pixel.cpp" // Pixel.cpp

int main()
{
    pixel aPixel(3.7, 4.1, 7);

    if (pixel::showPixelDetail(aPixel) != STATUS_OK)
    {
        std::cout << "Error showing details" << std::endl;
        return STATUS_ERROR;
    }
}
