#include "../Radar/Pixel/Pixel.cpp" // Pixel.cpp
#include "../Radar/Icon/Icon.cpp"   // Icon.cpp

int main()
{
    icon myIcon;
    pixel pixelOne(1, 2, 3);

    if (myIcon.setPixel(0, pixelOne) != STATUS_OK)
    {
        std::cout << "Error setting pixel" << std::endl;
        return STATUS_ERROR;
    }
}
