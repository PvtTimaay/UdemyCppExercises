#include <cstddef>
#include <cstdint>
#include <iostream>

#include "lib.h"

void remove_duplicates(std::int32_t *array, std::size_t &length)
{ //        {1, 1, 2, 3, 3, 4};


    for (std::size_t i = 0; i < length; i++)
    {
        if (array[0] == array[1])
        {
            rotate_left(array, length);
            array[length - 1] = 0;
        }
        else
            rotate_left(array, length);
    }


    /* while (array[0] == array[1])
    {
        tempAlloc = array;
        rotate_left(array, length);

        //array[length - 1] = length;
    }*/
    //std::cout << "Alloc: -> " << tempAlloc << " <- " << *tempAlloc << std::endl;
}

void rotate_left(std::int32_t *array, std::size_t length)
{

    std::int32_t temp = array[0];
    // Verschieben Sie alle anderen Werte des Arrays um 1 nach links.
    for (int i = 1; i < length; i++)
    {
        array[i - 1] = array[i];
        //std::cout << array[i];
    }
    array[length - 1] = temp;
}

void rotate_right(std::int32_t *array, std::size_t length)
{
    std::int32_t temp = array[length - 1];
    // Verschieben Sie alle anderen Werte des Arrays um 1 nach rechts.
    for (int i = length - 2; i >= 0; i--)
    {
        array[i + 1] = array[i];
        //std::cout << array[i];
    }
    array[0] = temp;
}
