#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mock_filter.hpp"
#include "mock_raw_temp_facade.hpp"
#include "thermal_reader.hpp"

class UtThermalReader : public ::testing::Test
{
  public:
    UtThermalReader();

  protected:
    ::testing::NiceMock<MockFilter> mock_filter_;
    ::testing::NiceMock<MockRawTempFacade> mock_raw_temp_facade_;
    ThermalReader                    temperature_reader_;
};
