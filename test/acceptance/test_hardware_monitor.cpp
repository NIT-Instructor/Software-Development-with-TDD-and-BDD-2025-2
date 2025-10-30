#include "at_hardware_monitor.hpp"
#include <thread>

struct HardwareMonitorConditions
{
    int num_of_ms_monitor_running;
    bool expected_alarm;
};

static const HardwareMonitorConditions kHardwareMonitorConditions[] =
    {{200, false}, {600, false}, {700, false}, {9500, true}, {100, false}};

class FixtureClassHardwareMonitor : public AtHardwareMonitor, public ::testing::WithParamInterface<HardwareMonitorConditions>
{
};

INSTANTIATE_TEST_SUITE_P(HardwareMonitorSuite, FixtureClassHardwareMonitor, ::testing::ValuesIn(kHardwareMonitorConditions));

TEST_P(FixtureClassHardwareMonitor, Given)
{
    hardware_monitor_.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(GetParam().num_of_ms_monitor_running));
    hardware_monitor_.stop();

    int over_calls = system_alarm_handler_.GetOverheatAlarmCount();
    int under_calls = system_alarm_handler_.GetUnderheatAlarmCount();

    // if an alarm is expected, require that at least one of the two was called
    if (GetParam().expected_alarm) {
        EXPECT_TRUE((over_calls > 0) || (under_calls > 0));
    } else {
        EXPECT_EQ(over_calls, 0);
        EXPECT_EQ(under_calls, 0);
    }

    // check alarm
}