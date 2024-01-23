#include "lib.h"
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

bool all_of(const std::vector<std::int32_t> &vector, const std::int32_t value)
{
    int temp = 0;
    for (int i = 0; i < vector.size(); i++)
    {
        if (vector[i] == value)
        {
            temp++;
        }
    }
    if (temp == vector.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool any_of(const std::vector<std::int32_t> &vector, const std::int32_t value)
{
    for (auto &item : vector)
    {
        if (item == value)
        {
            return true;
        }
    }
    return false;
}

bool none_of(const std::vector<std::int32_t> &vector, const std::int32_t value)
{
    for (auto &item : vector)
    {
        if (item == value)
        {
            return false;
        }
    }
    return true;
}

std::size_t count(const std::vector<std::int32_t> &vector, const std::int32_t value)
{
    int temp = 0;
    for (auto &item : vector)
    {
        if (item == value)
        {
            temp++;
        }
    }
    return temp;
}
