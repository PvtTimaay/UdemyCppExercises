#include <algorithm>
#include <ranges>

#include "lib.h"

namespace mystd
{

bool is_palindrom(std::string_view str)
{
    return std::equal(str.begin(), str.begin() + str.size()/2, str.rbegin());
}

bool starts_with(std::string_view str, std::string_view substr)
{
    if (str.size() < substr.size())
    {
        return false;
    }
    return std::equal(substr.begin(), substr.end(), str.begin());
}

bool ends_with(std::string_view str, std::string_view substr)
{
    if (str.size() < substr.size())
    {
        return false;
    }
    return std::equal(substr.begin(), substr.end(), str.end() - substr.size());
}

bool contains(std::string_view str, std::string_view substr)
{
   return std::search(str.begin(), str.end(), substr.begin(), substr.end()) != str.end();
}

std::size_t num_occurences(std::string_view str, std::string_view substr)
{
    std::size_t tempSize {};
    std::size_t tempPos {};
    while ((tempPos = str.find(substr, tempPos)) != std::string_view::npos)
    {
        tempSize++;
        tempPos += substr.size();
    }
    return tempSize;
}

} // namespace mystd
