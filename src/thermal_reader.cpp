#include "thermal_reader.hpp"

ThermalReader::ThermalReader(Filter& filter, RawTempFacade& facade)
    : filter_(filter), facade_(facade)
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
    //int raw_temp = 0;
    
    // Students need to use the injected RawTempFacade instance to
    // get the raw temperature from the C function.
    
    // Once raw_temp is fetched from the C library, it should be passed
    // to the filter to update the filtered data.
    int raw_temp =  facade_.ReadRawTemp();
    
    return filter_.UpdateFilterData(raw_temp);
}
