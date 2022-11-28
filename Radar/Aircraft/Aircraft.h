#pragma once

#include "../def.h"
#include "../Time/Time.h"

struct Aircraft
{
    unsigned long color = 0x6091ab;
    Point position{10, 10};
    Size size{10, 10};

    Aircraft(unsigned long new_col, Point new_pos, Size new_sz)
        : color(new_col), position(new_pos), size(new_sz){};

    Rect bounds() const;
};

struct Jet : public Aircraft
{
    Jet();

    void move();

    bool isTimeToMove();

    long time_at_last_move_ns_;
    long move_time_ns_{250'000'000};
    _Time time_;
};