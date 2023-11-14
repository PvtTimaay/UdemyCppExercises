#include <cstddef>
#include <cstdint>

#include "lib.h"
//              {3, 1, 4, 1, 5, 9, 2, 6};

bool all_of(const std::int32_t *array, const std::size_t length, const std::int32_t value)
{
    std::size_t Rainer = 0;
    if (array == nullptr || length <= 0)
    {
        return false;
    }
    for (size_t i = 0; i < length; i++)
    {

        if (array[i] == value)
        {
            Rainer++;
        }
    }
    if (Rainer == length)
    {
        return true;
    }
    else
        return false;
}

bool any_of(const std::int32_t *array, const std::size_t length, const std::int32_t value)
{
    if (array == nullptr || length <= 0)
    {
        return false;
    }
    std::size_t Rainer = 0;
    if (array == nullptr || length <= 0)
    {
        return false;
    }
    for (size_t i = 0; i < length; i++)
    {

        if (array[i] == value)
        {
            Rainer++;
        }
    }
    if (Rainer >= 1)
    {
        return true;
    }
    else
        return false;
}

bool none_of(const std::int32_t *array, const std::size_t length, const std::int32_t value)
{
    if (array == nullptr || length <= 0)
    {
        return false;
    }
    std::size_t Rainer = 0;
    if (array == nullptr || length <= 0)
    {
        return false;
    }
    for (size_t i = 0; i < length; i++)
    {

        if (array[i] == value)
        {
            Rainer++;
        }
    }
    if (Rainer == 0)
    {
        return true;
    }
    else
        return false;
}

std::size_t count(const std::int32_t *array, const std::size_t length, const std::int32_t value)
{
    if (array == nullptr || length <= 0)
    {
        return 0;
    }
    std::size_t Rainer = 0;
    if (array == nullptr || length <= 0)
    {
        return false;
    }
    for (size_t i = 0; i < length; i++)
    {

        if (array[i] == value)
        {
            Rainer++;
        }
    }
    return Rainer;
}
