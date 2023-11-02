#include <cstdint>

#include "lib.h"

std::uint32_t modulo(const std::uint32_t number_a, const std::uint32_t number_b)
{
    return number_a % number_b;
}

std::uint32_t sum_of_digits(std::uint32_t number)
{
    int temp = 0;
    do
    {
        number /= 10;
        temp++;
    } while (number > 0);

    return temp;
    /* if (number < 10 && number >= 0)
    {
        return 1;
    }

    else if (number > 9 && number < 100)
    {
        return 2;
    }
    else if (number > 99 && number < 1000)
    {
        return 3;
    }
    return 4;*/
}

std::uint32_t cross_sum(std::uint32_t number)
{
    // Initialisierung der Quersumme
    int quersumme = 0;

    // Addition der Ziffern der Zahl
    while (number > 0)
    {
        quersumme +=
            number % 10; // Komischer Trick, mit integer modulo 10 wird die ganz rechte Ziffer einer Zahl ausgegeben
        number /= 10; // Komischer Trick, mit integer geteilt druch 10 wird die ganz rechte Ziffer einer Zahl gelöscht
    }

    // Rückgabe der Quersumme
    return quersumme;
}
