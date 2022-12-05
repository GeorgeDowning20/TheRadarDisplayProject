#include "Aircraft.h"

Rect Aircraft::bounds() const
{
    return {position.x, position.y, size.width, size.height};
}

Jet_s::Jet_s() : Aircraft(0x3368ff, {100, 100}, {3, 3})
{
    icon_.set_Icon(1, JetIcon);
    time_at_last_move_ns_ = time_.time();
};

void Jet_s::move()
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

bool Jet_s::is_Time_To_Move()
{
    return ((time_.time() - time_at_last_move_ns_) >= move_time_ns_);
}

Heli_s::Heli_s() : Aircraft(0xff0000, {100, 100}, {3, 3})
{
    icon_.set_Icon(1, HeliIcon);
    time_at_last_move_ns_ = time_.time();
};

void Heli_s::move()
{
    int direction = std::rand() % 4;
    const int MOVE_DIST = 5;

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

bool Heli_s::is_Time_To_Move()
{
    return ((time_.time() - time_at_last_move_ns_) >= move_time_ns_);
}

Plane_s::Plane_s() : Aircraft(0x33ff4c, {100, 100}, {4, 4})
{
    icon_.set_Icon(1, PlaneIcon);
    time_at_last_move_ns_ = time_.time();
};

void Plane_s::move()
{
    int direction = std::rand() % 4;
    const int MOVE_DIST = 40;

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

bool Plane_s::is_Time_To_Move()
{
    return ((time_.time() - time_at_last_move_ns_) >= move_time_ns_);
}
