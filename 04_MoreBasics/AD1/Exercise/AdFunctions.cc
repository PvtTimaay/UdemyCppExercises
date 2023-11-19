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
    ego_vehicle.Id = EGO_VEHICLE_ID;
    ego_vehicle.Speed = 135;
    ego_vehicle.Lane = LaneAssociationType::CENTER_LANE;
}

void init_vehicle(VehicleType &vehicle,
                  const std::int32_t id,
                  const float speed_kph,
                  const float distance_m,
                  const LaneAssociationType lane)
{
    vehicle.Id = id;
    vehicle.Speed = speed_kph;
    vehicle.RelativeDistance = distance_m;
    vehicle.Lane = lane;
}

void init_vehicles(NeighborVehiclesType &vehicles) // TODO Init with a for loop maybe?
{
    for (int i = 0; i < NUM_VEHICLES_ON_LANE; i++)
    {
        vehicles.NearbyVehLeft[i] =   ? ;
        vehicles.NearbyVehCenter[i] = ? ;
        vehicles.NearbyVehRight[i] =  ? ;
    }
}

void print_vehicle(const VehicleType &vehicle)
{
}

void print_neighbor_vehicles(const NeighborVehiclesType &vehicles)
{
}
