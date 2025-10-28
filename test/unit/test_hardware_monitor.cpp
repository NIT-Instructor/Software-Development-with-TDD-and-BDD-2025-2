#include "ut_hardware_monitor.hpp"
#include <thread>
#include <chrono>

// Test to verify that CheckTemperature calls UpdateCurrentTemp on ThermalReader
TEST_F(UtHardwareMonitor, WhenCheckTemperatureIsCalled_ThenThermalReaderUpdateCurrentTempIsInvoked)
{
    // Setup expectations - HardwareMonitor should call UpdateCurrentTemp on ThermalReader
    EXPECT_CALL(mock_thermal_reader_, UpdateCurrentTemp())
        .Times(1)
        .WillOnce(testing::Return(true));
    
    // When CheckTemperature is called
    hardware_monitor_.CheckTemperature();
}

// User Story 6.1: Update Filter with Temperature Values at Regular Intervals
TEST_F(UtHardwareMonitor, GivenMonitoringIsActive_WhenMonitoringLoopRuns_ThenUpdateCurrentTempIsCalledPeriodically)
{
    // Setup expectations - HardwareMonitor should call UpdateCurrentTemp on ThermalReader multiple times
    EXPECT_CALL(mock_thermal_reader_, UpdateCurrentTemp())
        .Times(testing::AtLeast(3))
        .WillRepeatedly(testing::Return(true));
    
    // Start monitoring
    hardware_monitor_.StartMonitoring();

    // Let the monitoring run for a short duration
    std::this_thread::sleep_for(std::chrono::milliseconds(350));

    // Stop monitoring
    hardware_monitor_.StopMonitoring();
}

// User Story 6.2: Read and Compare Filtered Temperature Against THresholds
TEST_F(UtHardwareMonitor, GivenMonitoringIsActive_WhenMonitoringLoopRuns_ThenCheckTemperatureValidatesThresholds)
{
    // Setup expectations
    EXPECT_CALL(mock_codings_, GetMinThreshold())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(-30));
    EXPECT_CALL(mock_codings_, GetMaxThreshold())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(60));
    EXPECT_CALL(mock_thermal_reader_, ReadFilteredTemperature())
        .Times(3)
        .WillOnce(testing::Return(-35))   // Below min threshold
        .WillOnce(testing::Return(30))    // Within thresholds
        .WillOnce(testing::Return(65));   // Above max threshold
    EXPECT_CALL(mock_system_alarm_handler_, ReportOverheatingAlarm(65))
        .Times(1);
    
    // Start monitoring
    hardware_monitor_.StartMonitoring();

    // Let the monitoring run for a short duration
    std::this_thread::sleep_for(std::chrono::milliseconds(250));

    // Stop monitoring
    hardware_monitor_.StopMonitoring();
}