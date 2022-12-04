#pragma once

#include "../def.h"
#include "../Time/Time.h"
#include "../Icon/Icon.h"
#include "../Icon/Jet.inc"
#include "../Icon/Plane.inc"
#include "../Icon/Heli.inc"

// define a set of 16 pixels to represent a jet
struct Aircraft
{
    unsigned long color = 0x6091ab;
    Point position{10, 10};
    Size size{3, 3};
    icon icon_;

    Aircraft(unsigned long new_col, Point new_pos, Size new_sz)
        : color(new_col), position(new_pos), size(new_sz){};

    Rect bounds() const;
};

struct Jet_s : public Aircraft
{
    Jet_s();

    void move();

    bool isTimeToMove();

    long time_at_last_move_ns_;
    long move_time_ns_{250'000'000};
    _Time time_;
};

struct Heli_s : public Aircraft
{
    Heli_s();

    void move();

    bool isTimeToMove();

    long time_at_last_move_ns_;
    long move_time_ns_{500'000'000};
    _Time time_;
};

struct Plane_s : public Aircraft
{
    Plane_s();

    void move();

    bool isTimeToMove();

    long time_at_last_move_ns_;
    long move_time_ns_{800'000'000};
    _Time time_;
};
