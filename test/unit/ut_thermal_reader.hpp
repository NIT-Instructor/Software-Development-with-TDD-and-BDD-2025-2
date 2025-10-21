#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

 #include "../../inc/mock_filter.hpp"
 #include "../../inc/thermal_reader.hpp"

class UtThermalReader : public ::testing::Test
{
  // Students need to implement
  public:
    UtThermalReader();
    void SetUp() override;
    void TearDown() override;

  // Inject here ::testing::NiceMock<MockFilter>
  // and ThermalReader
};