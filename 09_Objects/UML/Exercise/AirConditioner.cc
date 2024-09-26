#include <iostream>

#include "AirConditioner.h"

int AirConditioner::measure()
{
    this->curr_temp = get_rand_float(lower_limit, upper_limit);
    return 0;
}

int AirConditioner::activate(int curr_temp)
{
}

bool AirConditioner::heat(int duration)
{
}

bool AirConditioner::cool(int duration)
{
}
