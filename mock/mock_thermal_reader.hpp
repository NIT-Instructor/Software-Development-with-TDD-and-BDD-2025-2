#pragma once

#include "mock_filter.hpp"
#include "mock_raw_temp_facade.hpp"
#include "thermal_reader.hpp"
#include <gmock/gmock.h>

class MockThermalReader : public ThermalReader
{
  public:
    MockThermalReader(MockFilter& mock_filter, MockRawTempFacade& mock_raw_temp_facade)
        : ThermalReader(mock_filter, mock_raw_temp_facade)
    {
    }

    MOCK_METHOD(int, ReadFilteredTemperature, ());
    MOCK_METHOD(bool, UpdateCurrentTemp, ());
};