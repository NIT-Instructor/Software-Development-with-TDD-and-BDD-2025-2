#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

// #include "mock_filter.hpp"
#include "thermal_reader.hpp"

class UtThermalReader : public ::testing::Test
{
  // Students need to implement

  public:
    UtThermalReader();
    void TearDown() override;
    void SetUp() override;

  // Inject here ::testing::NiceMock<MockFilter>
  // and ThermalReader
};