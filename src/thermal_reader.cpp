#include "thermal_reader.hpp"

ThermalReader::ThermalReader(Filter& filter, RawTempFacade& raw_temp_facade)
    : filter_(filter), raw_temp_facade_(raw_temp_facade)
{

}

int ThermalReader::ReadFilteredTemperature()
{
    return filter_.FilterData();
}

bool ThermalReader::UpdateCurrentTemp()
{    
    return filter_.UpdateFilterData(raw_temp_facade_.ReadRawTemp());
}
