//---------------------------------------------------------------------------//
/// @file def.h
/// @brief This file contains a set of definitions that are used throughout the project
/// @author G.Downing
/// @date 2020-11-24
/// @copyright (c) 2022 G. Downing
/// @details This file contains a set of definitions that are used throughout the project. This includes the definitions for the colours used in the project and the definitions for the size of the radar display window.
/// @details Doxygen Documentation for project: https://georgedowning20.github.io/TheRadarDisplayProject/index.html
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                        preprocessor directives
//---------------------------------------------------------------------------//

#pragma once         // Include guard
#include <algorithm> // std::min and std::max

//---------------------------------------------------------------------------//
//                        definitions
//---------------------------------------------------------------------------//

/// @brief structure to encapsulate a 2d point
/// @details This structure is used to represent a 2d point and contains the x and y coordinates of the point
struct Point
{
    int x, y; ///< The x and y coordinates of the point
};

/// @brief structure to encapsulate window
/// @details This structure is used to represent the window and contains the width and height of the window
struct Size
{
    int width, height; ///< The width and height of the window
};

/// @brief structure to encapsulate a 2d rectangle
/// @details This structure is used to represent a 2d rectangle and contains the x and y coordinates of each corner of the rectangle.
struct Rect
{
    int x, y;          ///< The x and y coordinates of the top left corner of the rectangle
    int width, height; ///< The width and height of the rectangle

    inline Point tl() const
    {
        return {std::min(x, x + width), std::min(y, y + height)}; // Return the top left corner of the rectangle
    }
    inline Point br() const
    {
        return {std::max(x, x + width), std::max(y, y + height)}; // Return the bottom right corner of the rectangle
    }
    inline Point tr() const
    {
        return {std::max(x, x + width), std::min(y, y + height)}; // Return the top right corner of the rectangle
    }
    inline Point bl() const
    {
        return {std::min(x, x + width), std::max(y, y + height)}; // Return the bottom left corner of the rectangle
    }
};