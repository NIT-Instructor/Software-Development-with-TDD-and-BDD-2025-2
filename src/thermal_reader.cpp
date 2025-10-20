#include "thermal_reader.hpp"

ThermalReader::ThermalReader(Filter &filter)
    : filter_(filter)
{
}

int ThermalReader::ReadFilteredTemperature()
{
    return filter_.FilterData();
}

bool ThermalReader::UpdateCurrentTemp()
{
    // Students will implement the logic to update current temperature
    return 0; // Placeholder value
}
