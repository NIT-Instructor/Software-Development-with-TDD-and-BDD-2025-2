#include "thermal_reader.hpp"

ThermalReader::ThermalReader(Filter& filter, RawTempFacade& raw_temp_facade)
    : filter_(filter), raw_temp_facade_(raw_temp_facade)
{
}

int ThermalReader::ReadFilteredTemperature() const
{
    return filter_.FilterData();
}

bool ThermalReader::UpdateCurrentTemp()
{
    constexpr int kMinThreshold = -30;
    constexpr int kMaxThreshold = 60;

    int raw_temp = raw_temp_facade_.ReadRawTemp();

    // Only update filter if temperature is within valid range
    if (raw_temp < kMinThreshold || raw_temp > kMaxThreshold) {
        return false;
    }

    return filter_.UpdateFilterData(raw_temp);
}
