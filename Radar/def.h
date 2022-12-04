#include <algorithm>

struct Point
{
    int x, y;
};

struct Size
{
    int width, height;
};

struct Rect
{
    int x, y;
    int width, height;

    inline Point tl() const
    {
        return {std::min(x, x + width), std::min(y, y + height)};
    }
    inline Point br() const
    {
        return {std::max(x, x + width), std::max(y, y + height)};
    }
    inline Point tr() const
    {
        return {std::max(x, x + width), std::min(y, y + height)};
    }
    inline Point bl() const
    {
        return {std::min(x, x + width), std::max(y, y + height)};
    }
};