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
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    // Stop monitoring
    hardware_monitor_.StopMonitoring();
}

// User Story 6.3: Validate Coding Plausibility
TEST_F(UtHardwareMonitor, WhenValidateCodingsIsCalled_ThenAreCodingsPlausableIsInvoked)
{
    EXPECT_CALL(mock_codings_, AreCodingsPlausable())
        .Times(1)
        .WillOnce(testing::Return(true));
    bool result = hardware_monitor_.ValidateCodings();
    EXPECT_TRUE(result);
}

TEST_F(UtHardwareMonitor, WhenValidateCodingsIsCalledWithInvalidCodings_ThenReturnsFalse)
{
    EXPECT_CALL(mock_codings_, AreCodingsPlausable())
        .Times(1)
        .WillOnce(testing::Return(false));
    bool result = hardware_monitor_.ValidateCodings();
    EXPECT_FALSE(result);
}

// User Story 6.4: Report Overheating Alarms
TEST_F(UtHardwareMonitor, WhenTemperatureExceedsMaxThreshold_ThenOverheatingAlarmIsReported)
{
    EXPECT_CALL(mock_thermal_reader_, UpdateCurrentTemp())
        .Times(1)
        .WillOnce(testing::Return(true));
    EXPECT_CALL(mock_thermal_reader_, ReadFilteredTemperature())
        .Times(1)
        .WillOnce(testing::Return(75));
    EXPECT_CALL(mock_codings_, GetMinThreshold())
        .Times(1)
        .WillOnce(testing::Return(-30));
    EXPECT_CALL(mock_codings_, GetMaxThreshold())
        .Times(1)
        .WillOnce(testing::Return(60));
    EXPECT_CALL(mock_system_alarm_handler_, ReportOverheatingAlarm(75))
        .Times(1);

    hardware_monitor_.CheckTemperature();
}

// User Story 6.5: Report Underheating Alarms
TEST_F(UtHardwareMonitor, WhenTemperatureFallsBelowMinThreshold_ThenUnderheatingAlarmIsReported)
{
    EXPECT_CALL(mock_thermal_reader_, UpdateCurrentTemp())
        .Times(1)
        .WillOnce(testing::Return(true));
    EXPECT_CALL(mock_thermal_reader_, ReadFilteredTemperature())
        .Times(1)
        .WillOnce(testing::Return(-40));
    EXPECT_CALL(mock_codings_, GetMinThreshold())
        .Times(1)
        .WillOnce(testing::Return(-30));
    EXPECT_CALL(mock_codings_, GetMaxThreshold())
        .Times(1)
        .WillOnce(testing::Return(60));
    EXPECT_CALL(mock_system_alarm_handler_, ReportUnderheatingAlarm(-40))
        .Times(1);

    hardware_monitor_.CheckTemperature();
}

TEST_F(UtHardwareMonitor, WhenTemperatureIsWithinThresholds_ThenNoAlarmIsReported)
{
    EXPECT_CALL(mock_thermal_reader_, UpdateCurrentTemp())
        .Times(1)
        .WillOnce(testing::Return(true));
    EXPECT_CALL(mock_thermal_reader_, ReadFilteredTemperature())
        .Times(1)
        .WillOnce(testing::Return(25));
    EXPECT_CALL(mock_codings_, GetMinThreshold())
        .Times(1)
        .WillOnce(testing::Return(-30));
    EXPECT_CALL(mock_codings_, GetMaxThreshold())
        .Times(1)
        .WillOnce(testing::Return(60));
    EXPECT_CALL(mock_system_alarm_handler_, ReportOverheatingAlarm(testing::_))
        .Times(0);
    EXPECT_CALL(mock_system_alarm_handler_, ReportUnderheatingAlarm(testing::_))
        .Times(0);

    hardware_monitor_.CheckTemperature();
}

// Test monitoring lifecycle
TEST_F(UtHardwareMonitor, WhenMonitoringIsStarted_ThenIsMonitoringActiveReturnsTrue)
{
    EXPECT_FALSE(hardware_monitor_.IsMonitoringActive());
    hardware_monitor_.StartMonitoring();
    EXPECT_TRUE(hardware_monitor_.IsMonitoringActive());
    hardware_monitor_.StopMonitoring();
}

TEST_F(UtHardwareMonitor, WhenMonitoringIsStopped_ThenIsMonitoringActiveReturnsFalse)
{
    hardware_monitor_.StartMonitoring();
    EXPECT_TRUE(hardware_monitor_.IsMonitoringActive());
    hardware_monitor_.StopMonitoring();
    EXPECT_FALSE(hardware_monitor_.IsMonitoringActive());
}

TEST_F(UtHardwareMonitor, WhenStartMonitoringIsCalledTwice_ThenOnlyOneThreadIsCreated)
{
    EXPECT_CALL(mock_thermal_reader_, UpdateCurrentTemp())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));

    hardware_monitor_.StartMonitoring();
    hardware_monitor_.StartMonitoring();
    EXPECT_TRUE(hardware_monitor_.IsMonitoringActive());
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    hardware_monitor_.StopMonitoring();
}

TEST_F(UtHardwareMonitor, WhenStopMonitoringIsCalledTwice_ThenNoErrorOccurs)
{
    hardware_monitor_.StartMonitoring();
    hardware_monitor_.StopMonitoring();
    hardware_monitor_.StopMonitoring();
    EXPECT_FALSE(hardware_monitor_.IsMonitoringActive());
}

TEST_F(UtHardwareMonitor, WhenTemperatureEqualsMaxThreshold_ThenNoAlarmIsReported)
{
    EXPECT_CALL(mock_thermal_reader_, UpdateCurrentTemp())
        .Times(1)
        .WillOnce(testing::Return(true));
    EXPECT_CALL(mock_thermal_reader_, ReadFilteredTemperature())
        .Times(1)
        .WillOnce(testing::Return(60));
    EXPECT_CALL(mock_codings_, GetMinThreshold())
        .Times(1)
        .WillOnce(testing::Return(-30));
    EXPECT_CALL(mock_codings_, GetMaxThreshold())
        .Times(1)
        .WillOnce(testing::Return(60));
    EXPECT_CALL(mock_system_alarm_handler_, ReportOverheatingAlarm(testing::_))
        .Times(0);
    EXPECT_CALL(mock_system_alarm_handler_, ReportUnderheatingAlarm(testing::_))
        .Times(0);

    hardware_monitor_.CheckTemperature();
}

TEST_F(UtHardwareMonitor, WhenTemperatureEqualsMinThreshold_ThenNoAlarmIsReported)
{
    // Setup expectations
    EXPECT_CALL(mock_thermal_reader_, UpdateCurrentTemp())
        .Times(1)
        .WillOnce(testing::Return(true));
    EXPECT_CALL(mock_thermal_reader_, ReadFilteredTemperature())
        .Times(1)
        .WillOnce(testing::Return(-30));
    EXPECT_CALL(mock_codings_, GetMinThreshold())
        .Times(1)
        .WillOnce(testing::Return(-30));
    EXPECT_CALL(mock_codings_, GetMaxThreshold())
        .Times(1)
        .WillOnce(testing::Return(60));
    EXPECT_CALL(mock_system_alarm_handler_, ReportOverheatingAlarm(testing::_))
        .Times(0);
    EXPECT_CALL(mock_system_alarm_handler_, ReportUnderheatingAlarm(testing::_))
        .Times(0);

    hardware_monitor_.CheckTemperature();
}