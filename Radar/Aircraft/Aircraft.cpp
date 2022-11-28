#include "Aircraft.h"

Rect Aircraft::bounds() const
{
    return {position.x, position.y, size.width, size.height};
}

Jet::Jet() : Aircraft(0xff0000, {100, 100}, {10, 10})
{
    time_at_last_move_ns_ = time_.time();
};

void Jet::move()
{
    int direction = std::rand() % 4;
    const int MOVE_DIST = 10;

    switch (direction)
    {
    case 0:
        position.y -= MOVE_DIST;
        break;
    case 1:
        position.y += MOVE_DIST;
        break;
    case 2:
        position.x -= MOVE_DIST;
        break;
    case 3:
        position.x += MOVE_DIST;
        break;
    }

    time_at_last_move_ns_ = time_.time();
}

bool Jet::isTimeToMove()
{
    return ((time_.time() - time_at_last_move_ns_) >= move_time_ns_);
}
