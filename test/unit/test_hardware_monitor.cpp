#include "gtest/gtest.h"
#include "ut_thermal_reader.hpp"
#include "ut_hardware_monitor.hpp"
//Project

TEST_F(UtHardwareMonitor, WhenUpdateIsCalled_ThenThermalReaderUpdateCurrentTempIsCalled)
{
    EXPECT_CALL(mock_temperature_reader_, UpdateCurrentTemp()).WillOnce(testing::Return(true));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    hardware_monitor_.Update();

}