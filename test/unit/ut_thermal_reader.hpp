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
    void TearDown() override;

  protected:
    MockFilter     mock_filter_;
    ThermalReader* temperature_reader_;
};