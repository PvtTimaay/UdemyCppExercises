#include "lib.h"
#include <cstdint>
#include <iostream>
#include <math.h>

double calculate_pi(const std::uint32_t num_iterations)
{
    double pi = 0.0;
    for (int i = 0; i < num_iterations; i++)
    {
        pi += 1.0 / (4.0 * i + 1.0) - 1.0 / (4.0 * i + 3.0);
    }
    pi *= 4.0;
    return pi;
}


void print_dec_to_bin(std::uint8_t value)
{ // Iterate over the bits of the decimal number, from most significant to least significant.

    std::cout << "Binary: 0b";
    for (int i = 7; i >= 0; i--)
    {

        int temp = std::pow(2, i);
        // Calculate the value of the current bit.
        if (temp <= value)
        {
            std::cout << "1";
            value -= temp;
        }
        else
        {
            std::cout << "0";
        }
    }
    std::cout << '\n';
}
