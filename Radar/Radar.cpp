#include "Radar.h"

Radar::Radar(AirSpace &air_space)
{
    airspace_ = &air_space;
    std::srand(std::time(nullptr));
    createGhosts();
}

void Radar::run()
{
    airspace_->updateGhosts();

    if (airspace_->update_flag_)
        gamedisplay_.redraw();

    if (is_running_)
    {

        if (!game_over)
            updateGhosts();

        if (getEvent())
        {
            handleEvent();
        }
    }
}

bool Radar::getEvent()
{
    if (XPending(gamedisplay_.getDisplay()))
    {
        XNextEvent(gamedisplay_.getDisplay(), &event_);
        // printf("EVENT: %d\n", event_.type);
        return true;
    }

    return false;
}

void Radar::draw()
{
    drawAllGhosts();
}

void Radar::createGhosts()
{
    ghosts_.clear();
    ghosts_.resize(50);
    const int MAXX = 800;
    const int MAXY = 600;

    for (auto &g : ghosts_)
    {
        g.position.x = (std::rand() % MAXX) / 10 * 10;
        g.position.y = (std::rand() % MAXY) / 10 * 10;
    }
}

void Radar::drawAllGhosts()
{
    for (auto &g : airspace_->jet_)
    {
        drawCharacter(g);
    }
}

void Radar::drawCharacter(const Aircraft &obj) const
{
    gamedisplay_.drawRect(obj.color,
                          obj.position.x,
                          obj.position.y,
                          obj.size.width,
                          obj.size.height);
}

void Radar::updateGhosts()
{
}

void Radar::handleEvent()
{
    if (event_.type == Expose)
    {
        draw();
    }
}
