#include "Radar.h"

Radar::Radar(AirSpace &air_space)
{
    airspace_ = &air_space;
    std::srand(std::time(nullptr));
}

void Radar::run()
{
    airspace_->updateGhosts();

    if (airspace_->update_flag_)
        RadarDisplay_.redraw();

    if (is_running_)
    {

        if (!STOP)
            if (getEvent())
            {
                handleEvent();
            }
    }
}

bool Radar::getEvent()
{
    if (XPending(RadarDisplay_.getDisplay()))
    {
        XNextEvent(RadarDisplay_.getDisplay(), &event_);
        // printf("EVENT: %d\n", event_.type);
        return true;
    }

    return false;
}

void Radar::drawAllGhosts()
{
    for (auto &g : airspace_->Jet)
    {
        drawCharacter(g);
    }

    for (auto &g : airspace_->Heli)
    {
        drawCharacter(g);
    }

    for (auto &g : airspace_->Plane)
    {
        drawCharacter(g);
    }
}

void Radar::drawCharacter(const Aircraft &obj) const
{
    RadarDisplay_.drawRect(obj.color,
                           obj.position.x,
                           obj.position.y,
                           obj.size.width,
                           obj.size.height);
}

void Radar::handleEvent()
{
    if (event_.type == Expose)
    {
        drawAllGhosts();
    }
}
