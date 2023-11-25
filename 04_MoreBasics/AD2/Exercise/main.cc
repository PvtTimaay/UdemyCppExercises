#include <cstring>
#include <iostream>
#include <numeric>

#include "AdFunctions.hpp"
#include "AdTypes.hpp"

int main()
{
    auto ego_vehicle = VehicleType{};
    auto vehicles = NeighborVehiclesType{};

    init_ego_vehicle(ego_vehicle);
    init_vehicles(vehicles);

    print_vehicle(ego_vehicle);
    print_neighbor_vehicles(vehicles);

    print_scene(ego_vehicle, vehicles);

    std::cout << "Compute forward (1sec)?: ";
    char input;
    std::cin >> input;
    while (input == 'y')
    {
        if (std::cin.fail())
        {
            std::cout << "Invalid input, please a literal";
        }
        else
        {
            compute_future_state(ego_vehicle, vehicles, 1);
            print_scene(ego_vehicle, vehicles);
        }
        std::cout << "Compute forward (1sec)?: ";
        std::cin >> input;
    }


    return 0;
}
