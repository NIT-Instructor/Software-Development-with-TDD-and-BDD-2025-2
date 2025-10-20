#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

//#include "mock_filter.hpp"
#include "thermal_reader.hpp"

class UtThermalReader : public ::testing::Test
{
  public:
    UtThermalReader();
    void SetUp() override;
    void TearDown() override;

  // Students need to implement

  // Inject here ::testing::NiceMock<MockFilter>
  // and ThermalReader
};