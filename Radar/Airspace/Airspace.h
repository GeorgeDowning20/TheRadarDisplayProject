//---------------------------------------------------------------------------//
/// @file Airspace.h
/// @brief This file contains the Airspace class Deceleration
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the Airspace class Deceleration. The Airspace class is responsible for storing the airspace data and updating the airspace data at the relevant time steps.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//

#pragma once // Include guard

#include "../Aircraft/Aircraft.h" // Aircraft class
#include <iostream>               // std::cout
#include <vector>                 // std::vector

//---------------------------------------------------------------------------//
//                           Class Deceleration
//---------------------------------------------------------------------------//

/// @brief Airspace class
/// @details This is the Airspace class. The Airspace class is responsible for storing the airspace data and updating the airspace data at the relevant time steps.
/// @date 2020-11-24
/// @author G.Downing

class Air_Space
{
public:
    /// @brief constructor the airspace class
    /// @param jets the number of jets in the airspace
    /// @param planes the number of planes in the airspace
    /// @param helicopters the number of helicopters in the airspace
    Air_Space(int jets, int planes, int helicopters);

    /// @brief deconstructor the airspace class
    ~Air_Space();

private:
    /// @brief update the airspace at the current time step
    /// @return 1
    bool _update_Aircraft();

    std::vector<Jet_s> Jet;     ///< The std::vector<Jet_s> instance used to store the jets
    std::vector<Heli_s> Heli;   ///< The std::vector<Heli_s> instance used to store the helicopters
    std::vector<Plane_s> Plane; ///< The std::vector<Plane_s> instance used to store the planes

    bool update_flag_; ///< The bool instance used to store the update flag

    friend class radarDisplay;
};
