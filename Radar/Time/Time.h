//---------------------------------------------------------------------------//
/// @file Time.h
/// @brief This file contains the Time class
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details The time class is responsible for updating the airspace at the relevant time steps.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//
#pragma once // Include guard

#include <chrono> // std::chrono

//---------------------------------------------------------------------------//
//                    Class Deceleration and definitions
//---------------------------------------------------------------------------//

/// @brief Time class
/// @details This is the Time class. The Time class is responsible for updating the airspace at the relevant time steps.
/// @date 2020-11-24
/// @author G.Downing
class _Time
{
public:
    /// @brief constructor the time class
    _Time()
    {
        start_ = std::chrono::high_resolution_clock::now(); // Set the start time to the current time
    }

    /// @brief interface with the time library to get the current time
    /// @return the current time
    long time()
    {
        std::chrono::duration<long, std::nano> elap = std::chrono::high_resolution_clock::now() - start_; // Calculate the elapsed time
        return elap.count();                                                                              // Return the elapsed time
    }

private:
    std::chrono::high_resolution_clock::time_point start_; ///< The std::chrono::high_resolution_clock::time_point instance used to store the start time
};