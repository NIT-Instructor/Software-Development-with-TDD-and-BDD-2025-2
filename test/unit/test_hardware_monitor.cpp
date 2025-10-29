#include "gtest/gtest.h"
#include "ut_hardware_monitor.hpp"

TEST_F(UtHardwareMonitor, WhenUpdateFilterTemperaturesIsCalled_ThenItShouldReturnTrue)
{
    auto result = hardware_monitor_.updateFilterTemperatures(0);
    EXPECT_TRUE(result);
}

TEST_F(UtHardwareMonitor, WhenReadFilteredTemperaturesIsCalled_ThenItShouldReturnAnInteger)
{
    auto result = hardware_monitor_.readFilteredTemperatures();
    EXPECT_EQ(result, 0);
}

TEST_F(UtHardwareMonitor, WhenCheckProvidedCodingIsCalled_ThenItShouldReturnTrue)
{
    auto result = hardware_monitor_.checkProvidedCoding();
    EXPECT_TRUE(result);
}