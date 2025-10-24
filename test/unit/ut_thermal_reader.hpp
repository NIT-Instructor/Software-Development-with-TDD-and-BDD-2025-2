#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mock_filter.hpp"
#include "thermal_reader.hpp"
#include "mock_raw_temp_facade.hpp"

class UtThermalReader : public ::testing::Test
{
  public:
    UtThermalReader();  // Constructor where dependencies will be injected

  protected:
    ::testing::NiceMock<MockFilter> mock_filter_;   // Mock for Filter
    ::testing::NiceMock<MockRawTempFacade> mock_raw_temp_facade_;
    ThermalReader                    temperature_reader_;  // Instance of ThermalReader with DI
    
};
