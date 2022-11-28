#pragma once
#include "../Aircraft/Aircraft.h"
#include <iostream>
#include <vector>

class AirSpace
{
public:
    AirSpace();
    ~AirSpace();

    bool updateGhosts();
    void createGhosts();

    void test();

private:
    std::vector<Jet> jet_;
    bool update_flag_;
    friend class Radar;
};
