#include "Lib.h"

namespace mystd
{
    void advance(It &it, DifferenceType n)
    {
        std::advance(it, n);
    }

    DifferenceType distance(It first, It last)
    {
        return std::distance(first, last);
    }

    It next(It it)
    {
        return std::next(it);
    }

    It prev(It it)
    {
        return std::prev(it);
    }
} // namespace mystd
