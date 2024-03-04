#pragma once

#include <cstdint>
#include <vector>

#include "lib.h"

namespace mystd
{

bool equal(Iterator first1, Iterator last1, Iterator first2)
{
    return std::equal(first1, last1, first2);
}

Iterator fill_n(Iterator first, std::size_t count, const std::int32_t &value)
{
   return std::fill_n(first, count, value);
}

void iota(Iterator first, Iterator last, std::int32_t value)
{
}

Iterator copy(Iterator first, Iterator last, Iterator d_first)
{
}

std::int32_t accumulate(Iterator first, Iterator last, std::int32_t init)
{
}

} // namespace mystd
