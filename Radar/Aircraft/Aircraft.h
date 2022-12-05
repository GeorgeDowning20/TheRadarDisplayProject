//---------------------------------------------------------------------------//
/// @file Aircraft.h
/// @brief This file contains the Airspace struct Deceleration
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains the Aircraft struct Deceleration. The Aircraft struct is responsible for storing the aircraft characteristic data for each type of aircraft, including icon and movement data.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//

#pragma once // Include guard

#include "../def.h"       // def.h
#include "../Time/Time.h" // Time class
#include "../Icon/Icon.h" // Icon class

#include "../Icon/Jet.inc"   // Jet icon
#include "../Icon/Plane.inc" // Plane icon
#include "../Icon/Heli.inc"  // Helicopter icon

//---------------------------------------------------------------------------//
//                           struct Deceleration
//---------------------------------------------------------------------------//

/// @brief Aircraft structure
/// @details This is the base struct for an aircraft. The Aircraft struct is responsible for storing the aircraft characteristic data for each type of aircraft.
/// @date 2020-11-24
/// @author G.Downing
struct Aircraft
{
    unsigned long color = 0x6091ab; ///< The unsigned long instance used to store the aircraft color
    Point position{10, 10};         ///< The Point instance used to store the aircraft position
    Size size{3, 3};                ///< The Size instance used to store the aircraft size
    icon icon_;                     ///< The icon instance used to store the aircraft icon

    /// @brief constructor the aircraft struct
    /// @param new_col the new aircraft color
    /// @param new_pos the new aircraft position
    /// @param new_sz   the new aircraft size
    Aircraft(unsigned long new_col, Point new_pos, Size new_sz)
        : color(new_col), position(new_pos), size(new_sz){};

    /// @brief return the bounding box for the aircraft
    /// @return the bounding box for the aircraft
    Rect bounds() const;
};

/// @brief Jet structure
/// @details This is the Jet struct. The Jet struct is responsible for storing the aircraft characteristic data for a jet.
/// @note This struct is derived from the Aircraft struct.
struct Jet_s : public Aircraft
{
    /// @brief constructor the jet struct
    Jet_s();

    /// @brief define movement characteristics for the jet
    void move();

    /// @brief define condition for updating the jet
    /// @return true if the jet should be updated
    bool is_Time_To_Move();

    long time_at_last_move_ns_;      ///< The long instance used to store the time at last move in nanoseconds
    long move_time_ns_{250'000'000}; ///< The long instance used to store the move time in nanoseconds
    _Time time_;                     ///< The _Time instance used to store the time
};

/// @brief Heli structure
/// @details This is the Heli struct. The Heli struct is responsible for storing the aircraft characteristic data for a Heli.
/// @note This struct is derived from the Aircraft struct.
struct Heli_s : public Aircraft
{
    /// @brief constructor the heli struct
    Heli_s();

    /// @brief define movement characteristics for the heli
    void move();

    /// @brief define condition for updating the heli
    /// @return true if the heli should be updated
    bool is_Time_To_Move();

    long time_at_last_move_ns_;      ///< The long instance used to store the time at last move in nanoseconds
    long move_time_ns_{500'000'000}; ///< The long instance used to store the move time in nanoseconds
    _Time time_;                     ///< The _Time instance used to store the time
};

/// @brief plane structure
/// @details This is the plane struct. The plane struct is responsible for storing the aircraft characteristic data for a plane.
/// @note This struct is derived from the Aircraft struct.
struct Plane_s : public Aircraft
{
    /// @brief constructor the plane struct
    Plane_s();

    /// @brief define movement characteristics for the plane
    void move();

    /// @brief define condition for updating the plane
    /// @return true if the plane should be updated
    bool is_Time_To_Move();

    long time_at_last_move_ns_;      ///< The long instance used to store the time at last move in nanoseconds
    long move_time_ns_{800'000'000}; ///< The long instance used to store the move time in nanoseconds
    _Time time_;                     ///< The _Time instance used to store the time
};
