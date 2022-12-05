#include "Airspace.h"

Air_Space::Air_Space(int jets, int planes, int helicopters)
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

Air_Space::~Air_Space()
{
}

bool Air_Space::update_Aircraft()
{
    update_flag_ = false;
    for (auto &g : Jet)
    {
        if (g.is_Time_To_Move())
        {
            g.move();
            update_flag_ = true;
        }
    }

    for (auto &g : Heli)
    {
        if (g.is_Time_To_Move())
        {
            g.move();
            update_flag_ = true;
        }
    }

    for (auto &g : Plane)
    {
        if (g.is_Time_To_Move())
        {
            g.move();
            update_flag_ = true;
        }
    }
    return 1;
}

void Air_Space::test()
{
    if (update_flag_)
        std::cout << update_flag_ << std::endl;
}