#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.hpp"
#include "AdFunctions.hpp"

float kph_to_mps(const float kph)
{
    return kph / 3.6f;
}

void init_ego_vehicle(VehicleType &ego_vehicle)
{
    ego_vehicle.Id = EGO_VEHICLE_ID;
    ego_vehicle.Speed = 135.0f;
    ego_vehicle.RelativeDistance = .0f;
    ego_vehicle.Lane = LaneAssociationType::CENTER_LANE;
}

void init_vehicle(VehicleType &vehicle,
                  const std::int32_t id,
                  const float speed_kph,
                  const float distance_m,
                  const LaneAssociationType lane)
{
    vehicle.Id = id;
    vehicle.Speed = kph_to_mps(speed_kph);
    vehicle.RelativeDistance = distance_m;
    vehicle.Lane = lane;
}

// Init each array index with the helper funtion void init_vehicle();

void init_vehicles(NeighborVehiclesType &vehicles)
{
    init_vehicle(vehicles.NearbyVehLeft[0], 0, 130.0f, 80.0f, LaneAssociationType::LEFT_LANE);
    init_vehicle(vehicles.NearbyVehLeft[1], 1, 110.0f, -20.0f, LaneAssociationType::LEFT_LANE);
    init_vehicle(vehicles.NearbyVehCenter[0], 2, 100.0f, 60.0f, LaneAssociationType::CENTER_LANE);
    init_vehicle(vehicles.NearbyVehCenter[1], 3, 140.0f, -40.0f, LaneAssociationType::CENTER_LANE);
    init_vehicle(vehicles.NearbyVehRight[0], 4, 95.0f, 40.0f, LaneAssociationType::RIGHT_LANE);
    init_vehicle(vehicles.NearbyVehRight[1], 5, 71.0f, -20.0f, LaneAssociationType::RIGHT_LANE);
}

void print_vehicle(const VehicleType &vehicle)
{
    std::cout << "vehicle id: " << vehicle.Id << '\n';
    std::cout << "vehicle speed: " << vehicle.Speed << " m/s" << '\n';
    std::cout << "vehicle distance: " << vehicle.RelativeDistance << " m" << '\n';
    std::cout << "vehicle lane: " << static_cast<int>(vehicle.Lane) << '\n' << '\n';
}

void print_neighbor_vehicles(const NeighborVehiclesType &vehicles)
{
    print_vehicle(vehicles.NearbyVehLeft[0]);
    print_vehicle(vehicles.NearbyVehLeft[1]);
    print_vehicle(vehicles.NearbyVehCenter[0]);
    print_vehicle(vehicles.NearbyVehCenter[1]);
    print_vehicle(vehicles.NearbyVehRight[0]);
    print_vehicle(vehicles.NearbyVehRight[1]);
}
