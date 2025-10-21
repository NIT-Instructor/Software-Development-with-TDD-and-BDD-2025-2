#include "thermal_reader.hpp"

ThermalReader::ThermalReader(Filter &filter)
    : filter_(filter)
{
}

int ThermalReader::ReadFilteredTemperature()
{
    // Read the value from the injected filter and return it
    return filter_.FilterData();
}

bool ThermalReader::UpdateCurrentTemp()
{
    // Students will implement the logic to update current temperature
    return 0; // Placeholder value
}
