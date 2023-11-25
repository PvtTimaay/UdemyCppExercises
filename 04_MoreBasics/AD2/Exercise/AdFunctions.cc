#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.hpp"
#include "AdFunctions.hpp"

float kph_to_mps(const float kph)
{
    return kph / 3.6F;
}

void init_ego_vehicle(VehicleType &ego_vehicle)
{
    ego_vehicle.id = EGO_VEHICLE_ID;
    ego_vehicle.speed_mps = kph_to_mps(135.0F);
    ego_vehicle.distance_m = 0.0F;
    ego_vehicle.lane = LaneAssociationType::CENTER;
}

void init_vehicle(VehicleType &vehicle,
                  const std::int32_t id,
                  const float speed_kph,
                  const float distance_m,
                  const LaneAssociationType lane)
{
    vehicle.id = id;
    vehicle.speed_mps = kph_to_mps(speed_kph);
    vehicle.distance_m = distance_m;
    vehicle.lane = lane;
}

void init_vehicles(NeighborVehiclesType &vehicles)
{
    init_vehicle(vehicles.vehicles_left_lane[0], 0, 130.0F, 80.0F, LaneAssociationType::LEFT);
    init_vehicle(vehicles.vehicles_left_lane[1], 1, 80.0F, -20.0F, LaneAssociationType::LEFT);
    init_vehicle(vehicles.vehicles_center_lane[0], 2, 80.0F, 50.0F, LaneAssociationType::CENTER);
    init_vehicle(vehicles.vehicles_center_lane[1], 3, 120.0F, -50.0F, LaneAssociationType::CENTER);
    init_vehicle(vehicles.vehicles_right_lane[0], 4, 110.0F, 30.0F, LaneAssociationType::RIGHT);
    init_vehicle(vehicles.vehicles_right_lane[1], 5, 90.0F, -30.0F, LaneAssociationType::RIGHT);
}

void print_vehicle(const VehicleType &vehicle)
{
    std::cout << "ID: " << vehicle.id << '\n';
    std::cout << "Speed (m/s): " << vehicle.speed_mps << '\n';
    std::cout << "Distance (m): " << vehicle.distance_m << '\n';
    std::cout << "Lane: " << static_cast<std::int32_t>(vehicle.lane) << '\n';
}

void print_neighbor_vehicles(const NeighborVehiclesType &vehicles)
{
    print_vehicle(vehicles.vehicles_left_lane[0]);
    print_vehicle(vehicles.vehicles_left_lane[1]);
    print_vehicle(vehicles.vehicles_center_lane[0]);
    print_vehicle(vehicles.vehicles_center_lane[1]);
    print_vehicle(vehicles.vehicles_right_lane[0]);
    print_vehicle(vehicles.vehicles_right_lane[1]);
}


int calculate_row_index_for_distance(float distance_m)
{
    // Assuming each row corresponds to a distance interval of 20 units
    // Adjust as needed based on the specific requirements of your simulation

    // Calculate the row index based on the distance
    int rowIndex = static_cast<int>((VIEW_RANGE_M - distance_m) / 20.0F);

    // Ensure the rowIndex is within the valid range
    rowIndex = std::max(0, std::min(rowIndex, 10));

    return rowIndex;
}


void print_scene(const VehicleType &ego_vehicle, const NeighborVehiclesType &vehicles)
{
    const int rows = 11;    // Zeilen (Abstandsmarkierungen)
    const int columns = 24; // Spalten (Spuren)

    char arrayz[rows][columns];
    int distAnd = 100;

    // Initialisierung des Arrays mit Leerzeichen
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arrayz[i][j] = ' ';
        }
    }

    // Markierung der Spuren
    for (int j = 0; j < columns; j += 6)
    {
        for (int i = 0; i < rows; i++)
        {
            arrayz[i][j] = '|';     // Rand der Spur
            arrayz[i][j + 1] = ' '; // Leerzeichen in der Spur
            arrayz[i][j + 2] = ' '; // Leerzeichen in der Spur
        }
    }

    // Setzen Sie das eigene Fahrzeugzeichen basierend auf der Lane-Eigenschaft
    int vehicleColumn = 0;
    if (ego_vehicle.lane == LaneAssociationType::LEFT)
    {
        vehicleColumn = 3; // Spalte für linke Spur
    }
    else if (ego_vehicle.lane == LaneAssociationType::CENTER)
    {
        vehicleColumn = 9; // Spalte für mittlere Spur
    }
    else if (ego_vehicle.lane == LaneAssociationType::RIGHT)
    {
        vehicleColumn = 15; // Spalte für rechte Spur
    }

    // Setzen Sie das Fahrzeugzeichen in die erste Zeile
    arrayz[5][vehicleColumn] = 'E';

    // Setzen der Fahrzeugzeichen der anderen
    for (std::size_t i = 0; i < NUM_VEHICLES_ON_LANE; i++)
    {
        // Left lane vehicles
        int leftLaneIndex = calculate_row_index_for_distance(vehicles.vehicles_left_lane[i].distance_m);
        arrayz[leftLaneIndex][3] = 'V';

        // Center lane vehicles
        int centerLaneIndex = calculate_row_index_for_distance(vehicles.vehicles_center_lane[i].distance_m);
        arrayz[centerLaneIndex][9] = 'V';

        // Right lane vehicles
        int rightLaneIndex = calculate_row_index_for_distance(vehicles.vehicles_right_lane[i].distance_m);
        arrayz[rightLaneIndex][15] = 'V';
    }

    // Setzen Sie die Zahlen für "L", "C" und "R" in die erste Zeile
    std::cout << "\t    L\t  C     R \n";
    // Ausgabe des Arrays
    for (int i = 0; i < rows; i++)
    {
        std::cout << distAnd << " \t ";
        distAnd -= 20;
        for (int j = 0; j < columns; j++)
        {
            std::cout << arrayz[i][j];
        }
        std::cout << std::endl;
    }
}


void compute_future_state(const VehicleType &ego_vehicle, NeighborVehiclesType &vehicles, const float seconds)
{
    for (std::size_t i = 0; i < NUM_VEHICLES_ON_LANE; i++)
    {
        std::cout << std::endl;
        vehicles.vehicles_left_lane[i].distance_m =
            vehicles.vehicles_left_lane[i].distance_m -
            (seconds * ego_vehicle.speed_mps - seconds * vehicles.vehicles_left_lane[i].speed_mps);
        vehicles.vehicles_center_lane[i].distance_m =
            vehicles.vehicles_center_lane[i].distance_m -
            (seconds * ego_vehicle.speed_mps - seconds * vehicles.vehicles_center_lane[i].speed_mps);
        vehicles.vehicles_right_lane[i].distance_m =
            vehicles.vehicles_right_lane[i].distance_m -
            (seconds * ego_vehicle.speed_mps - seconds * vehicles.vehicles_right_lane[i].speed_mps);
    }
}
