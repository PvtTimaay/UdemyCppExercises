
#include "lib.h"

void remove_duplicates(std::vector<std::int32_t> &vector)
{
    if (vector.size() == 0)
    {
        std::cout << "Vector == 0" << std::endl;
        return;
    }
    std::sort(vector.begin(), vector.end());
    auto last = std::unique(vector.begin(), vector.end());
    vector.erase(last, vector.end());
}

void rotate_left(std::vector<std::int32_t> &vector)
{
    if (vector.size() == 0)
    {
        std::cout << "Vector == 0" << std::endl;
        return;
    }
    auto temp = vector.front();
    vector.erase(vector.begin());
    vector.push_back(temp);
}

void rotate_right(std::vector<std::int32_t> &vector)
{
    if (vector.size() == 0)
    {
        std::cout << "Vector == 0" << std::endl; // {1, 1, 2, 3, 3, 4};
        return;
    }
    auto temp = vector.back();
    for (size_t i = vector.size() - 1; i > 0; --i)
    {
        vector[i] = vector[i - 1];
    }
    vector[0] = temp;
}

void swap_boundary_values(std::vector<std::int32_t> &vector)
{
    auto temp = vector.front();
    auto temp1 = vector.back();
    vector.front() = temp1;
    vector.back() = temp;
}
