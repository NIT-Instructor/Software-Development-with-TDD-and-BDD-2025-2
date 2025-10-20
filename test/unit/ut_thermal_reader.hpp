#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mock_filter.hpp"
#include "thermal_reader.hpp"

class UtThermalReader : public ::testing::Test
{
public:
  UtThermalReader();
  void SetUp() override;

protected:
  ::testing::NiceMock<MockFilter> mock_filter_;

  // ThermalReader under test, injected with the mock filter
  ThermalReader temperature_reader_;
};