#include "thermal_reader.hpp"

ThermalReader::ThermalReader(Filter& filter, RawTempFacade& rawTempFacade)
    : filter_(filter), rawTempFacade_(rawTempFacade)
{
    // Students need to add Dependency Injection for RawTempFacade.
    // This will allow ThermalReader to use an instance of RawTempFacade
    // to fetch raw temperature data from the C library.
}

int ThermalReader::ReadFilteredTemperature()
{
    return filter_.FilterData();
}

bool ThermalReader::UpdateCurrentTemp()
{
    int raw_temp = 0;
    
    // Students need to use the injected RawTempFacade instance to
    // get the raw temperature from the C function.
    
    raw_temp = rawTempFacade_.ReadRawTemp();
    
    // Once raw_temp is fetched from the C library, it should be passed
    // to the filter to update the filtered data.
    
    return filter_.UpdateFilterData(raw_temp);
}
