#include "Airspace.h"

AirSpace::AirSpace()
{
    createGhosts();
}

AirSpace::~AirSpace()
{
}

bool AirSpace::updateGhosts()
{
    update_flag_ = false;
    for (auto &g : jet_)
    {
        if (g.isTimeToMove())
        {
            g.move();
            update_flag_ = true;

            return 1;
        }
    }
    return 0;
}

void AirSpace::createGhosts()
{
    jet_.clear();
    jet_.resize(10);
    const int MAXX = 800;
    const int MAXY = 600;

    for (auto &g : jet_)
    {
        g.position.x = (std::rand() % MAXX) / 10 * 10;
        g.position.y = (std::rand() % MAXY) / 10 * 10;
    }
}

void AirSpace::test()
{
    if (update_flag_)
        std::cout << update_flag_ << std::endl;
}