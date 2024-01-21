#include <cstddef>
#include <cstdint>
#include <vector>

#include "lib.h"

void remove_duplicates(std::vector<std::int32_t> &vector)
{
    if (vector.size() == 0)
    {
        std::cout << "Vector == 0" << std::endl;
        return;
    }
    for (size_t i = 0; i < vector.size(); i++)
    {
        if (vector[i] == vector[i + 1]) // {1, 1, 2, 3, 3, 4};
        {
            rotate_left(vector);
            vector.pop_back();
        }
        else
        {
            rotate_left(vector);
        }
    }
}

void rotate_left(std::vector<std::int32_t> &vector)
{
    if (vector.size() == 0)
    {
        std::cout << "Vector == 0" << std::endl;
        return;
    }
    auto temp = vector.front();
    for (size_t i = 0; i < vector.size(); i++)
    {
        vector[i] = vector[i + 1];
    }
    vector.back() = temp;
}

void rotate_right(std::vector<std::int32_t> &vector)
{
}

void swap_boundary_values(std::vector<std::int32_t> &vector)
{
}
