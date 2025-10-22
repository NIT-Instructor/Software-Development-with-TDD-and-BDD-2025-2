#include "thermal_reader.hpp"

ThermalReader::ThermalReader(Filter &filter)
    : filter_(filter)
{
}

int ThermalReader::ReadFilteredTemperature()
{
    // Students will implement the logic to read filtered temperature using FilterData()
    (void)filter_.FilterData();
    return 33; // Placeholder value
}

bool ThermalReader::UpdateCurrentTemp()
{
    // Students will implement the logic to update current temperature
    return 0; // Placeholder value
}
