#include "ut_thermal_reader.hpp"

UtThermalReader::UtThermalReader()
    : mock_filter_(), mock_raw_temp_facade_(), temperature_reader_(mock_filter_, mock_raw_temp_facade_)
{
    // Students need to inject any additional dependencies required for 
    // processing temperature data (e.g., RawTempFacade) when expanding the functionality.
}
