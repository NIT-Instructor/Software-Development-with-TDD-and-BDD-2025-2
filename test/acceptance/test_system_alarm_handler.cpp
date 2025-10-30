#include "at_thermal_reader.hpp"
#include "at_hardware_monitor.hpp"
#include "system_alarm_handler.hpp"
#include "codings.hpp"
#include "at_system_alarm_handler.hpp"

#include <gtest/gtest.h>
#include <thread>
#include <chrono>
#include <sstream>
#include <iostream>

struct HardwareMonitorAlarmConditions
{
    int min_threshold;
    int max_threshold;
    std::string expected_output;
};

static const HardwareMonitorAlarmConditions kHardwareMonitorAlarmConditions[] = {
    {50, 100, "[ALARM] Underheating detected!\n"},
    {-5, -3, "[ALARM] Overheating detected!\n"},
    {0, 500, "The value is within limits\n"}};

class FixtureClassHardwareMonitorAlarm
    : public AtHardwareMonitorWithAlarm,
    public ::testing::WithParamInterface<HardwareMonitorAlarmConditions>
{
};

INSTANTIATE_TEST_SUITE_P(HardwareMonitorAlarmSuite,
                         FixtureClassHardwareMonitorAlarm,
                         ::testing::ValuesIn(kHardwareMonitorAlarmConditions));

TEST_P(FixtureClassHardwareMonitorAlarm, WhenTemperatureIsOutOfThresholds_ThenProperAlarmIsReported)
{
    const auto &param = GetParam();

    codings_.SetMinThreshold(param.min_threshold);
    codings_.SetMaxThreshold(param.max_threshold);

    string result = hardware_monitor_.checkValueAndReport(theremal_reader_, codings_);

    EXPECT_EQ(result, param.expected_output);
}

