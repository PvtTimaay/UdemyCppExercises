#pragma once

#include <cstdint>

#include "AdConstants.hpp"

enum class LaneAssociationType
{
    UNKNOWN_LANE,
    LEFT_LANE,
    CENTER_LANE,
    RIGHT_LANE,
};

struct VehicleType
{
    int Id = 0;
    LaneAssociationType Lane;
    float Speed = .0f;            //(meter/s)
    float RelativeDistance = .0f; //(meter)
};

struct NeighborVehiclesType
{
    // Array for nearby vehicles on left lane (2 vehicles in total)
    VehicleType NearbyVehLeft[NUM_VEHICLES_ON_LANE];
    // Array for nearby vehicles on center lane (2 vehicles in total)
    VehicleType NearbyVehCenter[NUM_VEHICLES_ON_LANE];
    // Array for nearby vehicles on right lane (2 vehicles in total)
    VehicleType NearbyVehRight[NUM_VEHICLES_ON_LANE];
};
