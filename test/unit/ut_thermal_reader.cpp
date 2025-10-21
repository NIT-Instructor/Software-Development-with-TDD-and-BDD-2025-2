#include "ut_thermal_reader.hpp"

UtThermalReader::UtThermalReader()
    : mock_filter_(), temperature_reader_(mock_filter_)
{
}

void UtThermalReader::SetUp()
{
    // default mock behavior can be set here if required
}