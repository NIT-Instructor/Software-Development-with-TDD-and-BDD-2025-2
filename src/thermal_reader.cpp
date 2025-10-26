#include "thermal_reader.hpp"

ThermalReader::ThermalReader(Filter& filter, RawTempFacade& raw_temp_facade,
                             int min_threshold, int max_threshold)
        : filter_(filter)
        , raw_temp_facade_(raw_temp_facade)
        , min_threshold_(min_threshold)
        , max_threshold_(max_threshold)
{
}

int ThermalReader::ReadFilteredTemperature() const
{
    return filter_.FilterData();
}

bool ThermalReader::UpdateCurrentTemp()
{
    int raw_temp = raw_temp_facade_.ReadRawTemp(1);

    // Ensure raw temperature is within configured bounds
    if (raw_temp < min_threshold_)
        raw_temp = min_threshold_;
    else if (raw_temp > max_threshold_)
        raw_temp = max_threshold_;
        
    return filter_.UpdateFilterData(raw_temp);
}
