#include "ut_thermal_reader.hpp"

UtThermalReader::UtThermalReader()
    : mock_filter_(), temperature_reader_(mock_filter_, mock_raw_temp_facade_)
{

}