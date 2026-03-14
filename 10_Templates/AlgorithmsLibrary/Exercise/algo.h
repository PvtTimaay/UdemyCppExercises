#pragma once

namespace mystd
{

template <typename InputIter1, typename InputIter2>
bool equal(InputIter1 first1, InputIter1 last1, InputIter2 first2)
{
    for (; first1 != last1; ++first1, ++first2)
    {
        if (*first1 != *first2)
        {
            return false;
        }
    }
    return true;
}

template <typename OutputIter, typename Size, typename T>
OutputIter fill_n(OutputIter first, Size count, const T &value)
{
    for (Size i = 0; i < count; ++i)
    {
        *first++ = value;
    }
    return first;
}

template <typename ForwardIter, typename T>
void iota(ForwardIter first, ForwardIter last, T value)
{
    for (; first != last; ++first, ++value)
    {
        *first = value;
    }
}

template <typename InptIter, typename OutputIter>
OutputIter copy(InptIter first, InptIter last, OutputIter d_first)
{
    for (; first != last; ++first, ++d_first)
    {
        *d_first = *first;
    }
    return d_first;
}

template <typename InputIter, typename T>
T accumulate(InputIter first, InputIter last, T init)
{
    for (; first != last; ++first)
    {
        init += *first;
    }
    return init;
}

} // namespace mystd
