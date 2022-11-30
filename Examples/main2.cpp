#include "../Radar/Pixel/Pixel.cpp" // Pixel.cpp

int main()
{
    pixel aPixel(3.7, 4.1, 7);

    std::cout << "Pixel at (" << aPixel.getX()
              << ", " << aPixel.getY()
              << ") has a brightness of " << unsigned(aPixel.getBrightness())
              << " \n " << std::endl;
}
