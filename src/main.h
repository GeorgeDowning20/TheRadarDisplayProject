//---------------------------------------------------------------------------//
/// @file main.h
/// @brief This file contains status enums for the program
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains status enums for the program. These enums are used to indicate the status of the program. They are used to indicate if a function has completed successfully or if an error has occurred.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

#pragma once // Include guard

/// @brief This enum is used to indicate the status of the program
/// @details This enum is used to indicate the status of the program. It is used to indicate if a function has completed successfully or if an error has occurred.
enum status_e
{
    STATUS_OK = 0,     ///< The function completed successfully
    STATUS_ERROR = 1,  ///< The function did not complete successfully
    STATUS_UNKNOWN = 2 ///< The status of the function is unknown
};
