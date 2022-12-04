#include "Airspace.h"

AirSpace::AirSpace(int jets, int planes, int helicopters)
{
    Jet.clear();
    Jet.resize(jets);
    const int MAXX = 800;
    const int MAXY = 600;
    for (auto &g : Jet)
    {
        g.position.x = (std::rand() % MAXX) / 10 * 10;
        g.position.y = (std::rand() % MAXY) / 10 * 10;
    }

    Heli.clear();
    Heli.resize(helicopters);
    for (auto &g : Heli)
    {
        g.position.x = (std::rand() % MAXX) / 10 * 10;
        g.position.y = (std::rand() % MAXY) / 10 * 10;
    }

    Plane.clear();
    Plane.resize(planes);
    for (auto &g : Plane)
    {
        g.position.x = (std::rand() % MAXX) / 10 * 10;
        g.position.y = (std::rand() % MAXY) / 10 * 10;
    }
}

AirSpace::~AirSpace()
{
}

bool AirSpace::updateGhosts()
{
    update_flag_ = false;
    for (auto &g : Jet)
    {
        if (g.isTimeToMove())
        {
            g.move();
            update_flag_ = true;
        }
    }

    for (auto &g : Heli)
    {
        if (g.isTimeToMove())
        {
            g.move();
            update_flag_ = true;
        }
    }

    for (auto &g : Plane)
    {
        if (g.isTimeToMove())
        {
            g.move();
            update_flag_ = true;
        }
    }
    return 1;
}

void AirSpace::test()
{
    if (update_flag_)
        std::cout << update_flag_ << std::endl;
}