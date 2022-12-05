#pragma once
#include "../Aircraft/Aircraft.h"
#include <iostream>
#include <vector>

class AirSpace
{
public:
    AirSpace(int jets, int planes, int helicopters);
    ~AirSpace();

    bool updateGhosts();
    void test();

private:
    std::vector<Jet_s> Jet;
    std::vector<Heli_s> Heli;
    std::vector<Plane_s> Plane;

    bool update_flag_;
    friend class radarDisplay;
};
