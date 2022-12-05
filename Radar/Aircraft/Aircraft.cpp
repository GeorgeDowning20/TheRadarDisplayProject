//---------------------------------------------------------------------------//
/// @file Aircraft.cpp
/// @brief This file contains the Airspace struct Definitions
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the Aircraft struct Definitions. The Aircraft struct is responsible for storing the aircraft characteristic data for each type of aircraft, including icon and movement data.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//

#include "Aircraft.h" // Aircraft structures

//---------------------------------------------------------------------------//
//                           struct Definitions
//---------------------------------------------------------------------------//

/// @details This function returns the bounding box for the aircraft
Rect Aircraft::bounds() const
{
    return {position.x, position.y, size.width, size.height}; // Return the bounding box for the aircraft
}

/// @details This function is the constructor for the jet struct. The icon is set to the jet icon, and the last update time is set to the current time to initialise the movement.
Jet_s::Jet_s() : Aircraft(0x3368ff, {100, 100}, {3, 3})
{
    icon_.set_Icon(1, JetIcon);           // Set the icon to the jet icon
    time_at_last_move_ns_ = time_.time(); // Set the last update time to the current time
};

/// @details This function defines the movement characteristics for the jet. The jet moves randomly at a the defined speed.
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

/// @details This functions polls the time since the last update, and if the time is greater than the defined update time, the aircraft moves. This regulates the update rate of the aircraft.
bool Jet_s::is_Time_To_Move()
{
    return ((time_.time() - time_at_last_move_ns_) >= move_time_ns_);
}

/// @details This function is the constructor for the plane struct. The icon is set to the plane icon, and the last update time is set to the current time to initialise the movement.
Plane_s::Plane_s() : Aircraft(0x33ff4c, {100, 100}, {4, 4})
{
    icon_.set_Icon(1, PlaneIcon);
    time_at_last_move_ns_ = time_.time();
};

/// @details This function defines the movement characteristics for the plane. The plane moves randomly at a the defined speed.
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

/// @details This functions polls the time since the last update, and if the time is greater than the defined update time, the aircraft moves. This regulates the update rate of the aircraft.
bool Plane_s::is_Time_To_Move()
{
    return ((time_.time() - time_at_last_move_ns_) >= move_time_ns_);
}

/// @details This function is the constructor for the helicopter struct. The icon is set to the helicopter icon, and the last update time is set to the current time to initialise the movement.
Heli_s::Heli_s() : Aircraft(0xff0000, {100, 100}, {3, 3})
{
    icon_.set_Icon(1, HeliIcon);
    time_at_last_move_ns_ = time_.time();
};

/// @details This function defines the movement characteristics for the helicopter. The helicopter moves randomly at a the defined speed.
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

/// @details This functions polls the time since the last update, and if the time is greater than the defined update time, the aircraft moves. This regulates the update rate of the aircraft.
bool Heli_s::is_Time_To_Move()
{
    return ((time_.time() - time_at_last_move_ns_) >= move_time_ns_);
}