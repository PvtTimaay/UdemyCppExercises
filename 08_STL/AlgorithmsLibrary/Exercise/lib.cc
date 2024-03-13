#pragma once

#include <algorithm>
#include <cstdint>
#include <vector>
#include <numeric>

#include "lib.h"

namespace mystd
{

bool equal(Iterator first1, Iterator last1, Iterator first2)
{
    //return std::equal(first1, last1, first2);
    for (;first1 != last1; first1++, first2++)
    {
        if (*first1 != *first2)
        {
            return false;
        }
    }
    return true;
}

Iterator fill_n(Iterator first, std::size_t count, const std::int32_t &value)
{
  // return std::fill_n(first, count, value);
   for (std::size_t i = 0; i < count; i++, first++)
   {
        *first = value;
   }
   return first;
}

void iota(Iterator first, Iterator last, std::int32_t value)
{
   //std::iota(first, last, value);
    while (first != last)
    {
        *first = value;
        value++;
        first++;
    }
}

Iterator copy(Iterator first, Iterator last, Iterator d_first)
{
    //return std::copy(first, last, d_first);
    while (first != last)
    {
        *d_first = *first;
        first++;
        d_first++;
    }
    return d_first;
}

std::int32_t accumulate(Iterator first, Iterator last, std::int32_t init)
{
    //return std::accumulate(first, last, init);
    for (; first != last; first++)
    {
        init += *first;
    }
    return init;
}

} // namespace mystd
