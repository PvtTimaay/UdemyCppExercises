#include <iostream>
#include <chrono>
#include <thread>
#include "AirConditioner.h"

int AirConditioner::measure()
{
    float lower_limit {-20};
    float upper_limit {45};
    this->curr_temp = get_rand_float(lower_limit, upper_limit);
    return curr_temp;
}

int AirConditioner::activate(int curr_temp)
{
    if (curr_temp >= -20 && curr_temp <= 45)
    {
        if (this->target_temp > curr_temp)
        {
            int evaTime = target_temp - curr_temp;
            evaTime *= 2;
            std::cout << "calls heat methode\n";
            std::cout << "heating needs " << evaTime << " minutes to finish\n";
            heat(evaTime);

            return evaTime;
        }
        else
        {
            int evaTimeCool = target_temp - curr_temp;
            std::cout << "calls cool methode\n";
            std::cout << "cooling needs " << evaTimeCool << " minutes to finish\n";
            cool(evaTimeCool);

            return evaTimeCool;
        }
    }
    else
    {
        std::cerr << "error, curr_temp ist under -20 or over 45 degree celsius\n\n";
        return -1;
    }
}

bool AirConditioner::heat(int duration)
{
    std::cout << "target temp is " << target_temp << '\n';
    while (target_temp != curr_temp)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "current temp is " << curr_temp << "!\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        curr_temp++;
    }

    return true;
}

bool AirConditioner::cool(int duration)
{
    std::cout << "target temp is " << target_temp << '\n';
    while (target_temp != curr_temp)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "current temp is " << curr_temp << "!\n";
        curr_temp--;
    }

    return true;
}
