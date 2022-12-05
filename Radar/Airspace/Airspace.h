#pragma once
#include "../Aircraft/Aircraft.h"
#include <iostream>
#include <vector>

class Air_Space
{
public:
    Air_Space(int jets, int planes, int helicopters);
    ~Air_Space();

    bool update_Aircraft();
    void test();

private:
    std::vector<Jet_s> Jet;
    std::vector<Heli_s> Heli;
    std::vector<Plane_s> Plane;

    bool update_flag_;
    friend class radarDisplay;
};
