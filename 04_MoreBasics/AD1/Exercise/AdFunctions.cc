#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.hpp"
#include "AdFunctions.hpp"

float kph_to_mps(const float kph)
{
    return kph / 3.6;
}

void init_ego_vehicle(VehicleType &ego_vehicle)
{
    ego_vehicle.Id = -1;
    ego_vehicle.Speed = 135;
    ego_vehicle.Lane = LaneAssociationType::CENTER_LANE;
}

void init_vehicle(VehicleType &vehicle,
                  const std::int32_t id,
                  const float speed_kph,
                  const float distance_m,
                  const LaneAssociationType lane)
{
}

void init_vehicles(NeighborVehiclesType &vehicles)
{
    vehicles.NearbyVehLeft[0];
    vehicles.NearbyVehCenter[0];
    vehicles.NearbyVehRight[0];
}

void print_vehicle(const VehicleType &vehicle)
{
}

void print_neighbor_vehicles(const NeighborVehiclesType &vehicles)
{
}
