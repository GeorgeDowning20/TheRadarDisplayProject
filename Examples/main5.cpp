#include "../Radar/Pixel/Pixel.cpp" // Pixel.cpp
#include "../Radar/Icon/Icon.cpp"   // Icon.cpp

int main()
{
    icon myIcon;

    if (myIcon.initialiseAsDefaultDiagonalLine(15) != STATUS_OK)
    {
        std::cout << "Error creating diagonal icon" << std::endl;
        return STATUS_ERROR;
    }

    if (myIcon.showDetails() != STATUS_OK)
    {
        std::cout << "Error showing details" << std::endl;
        return STATUS_ERROR;
    }
}