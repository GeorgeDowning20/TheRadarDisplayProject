//---------------------------------------------------------------------------//
/// @file Airspace.cpp
/// @brief This file contains the Airspace class Definitions
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the Airspace class Definitions. The Airspace class is responsible for storing the airspace data and updating the airspace data at the relevant time steps.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//

#include "Airspace.h" // Airspace class

//---------------------------------------------------------------------------//
//                           Class Definitions
//---------------------------------------------------------------------------//

/// @details constructor the airspace class. the number of jets, planes and helicopters are passed to the constructor. the constructor then creates the relevant number of aircraft and stores them in the relevant vectors. random stating positions are generated for each aircraft.
Air_Space::Air_Space(int jets, int planes, int helicopters)
{
    Jet.clear();          // Clear the Jet vector
    Jet.resize(jets);     // Resize the Jet vector to the number of jets
    const int MAXX = 800; // The const int instance used to store the maximum x value
    const int MAXY = 600; // The const int instance used to store the maximum y value
    for (auto &g : Jet)   // iterate through all aircraft in the vector
    {
        g.position.x = (std::rand() % MAXX) / 10 * 10; // Set the x position of the aircraft to a random value between 0 and 800
        g.position.y = (std::rand() % MAXY) / 10 * 10; // Set the y position of the aircraft to a random value between 0 and 600
    }

    Heli.clear();             // Clear the Heli vector
    Heli.resize(helicopters); // Resize the Heli vector to the number of helicopters
    for (auto &g : Heli)      // iterate through all aircraft in the vector
    {
        g.position.x = (std::rand() % MAXX) / 10 * 10; // Set the x position of the aircraft to a random value between 0 and 800
        g.position.y = (std::rand() % MAXY) / 10 * 10; // Set the y position of the aircraft to a random value between 0 and 600
    }

    Plane.clear();        // Clear the Plane vector
    Plane.resize(planes); // Resize the Plane vector to the number of planes
    for (auto &g : Plane) // iterate through all aircraft in the vector
    {
        g.position.x = (std::rand() % MAXX) / 10 * 10; // Set the x position of the aircraft to a random value between 0 and 800
        g.position.y = (std::rand() % MAXY) / 10 * 10; // Set the y position of the aircraft to a random value between 0 and 600
    }
}

/// @details deconstructor the airspace class (empty)
Air_Space::~Air_Space()
{
}

/// @details update the airspace at the current time step. the update flag is set to true. the aircraft are then updated. the update flag is then set to false. the update flag is used to ensure that the aircraft are only updated once per time step.
bool Air_Space::_update_Aircraft()
{
    update_flag_ = false; // Set the update flag to false
    for (auto &g : Jet)   // iterate through all aircraft in the vector
    {
        if (g.is_Time_To_Move()) // Check if the aircraft is ready to move
        {
            g.move();            // Move the aircraft
            update_flag_ = true; // Set the update flag to true
        }
    }

    for (auto &g : Heli) // iterate through all aircraft in the vector
    {
        if (g.is_Time_To_Move()) // Check if the aircraft is ready to move
        {
            g.move();            // Move the aircraft
            update_flag_ = true; // Set the update flag to true
        }
    }

    for (auto &g : Plane) // iterate through all aircraft in the vector
    {
        if (g.is_Time_To_Move()) // Check if the aircraft is ready to move
        {
            g.move();            // Move the aircraft
            update_flag_ = true; // Set the update flag to true
        }
    }
    return 1; // Return 1
}
