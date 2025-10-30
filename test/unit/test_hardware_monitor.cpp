#include "ut_hardware_monitor.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

#define UNDERHEATING    1
#define OVERHEATING     2
#define PLAUSIBLE       3

TEST_F(UtHardwareMonitor, WhenReportUnderheatingAlarmIsCalled_ThenLogUnderheatingAlarmToConsole) {
    int output = hardware_monitor.hwm_function();

    EXPECT_EQ(output, UNDERHEATING);
}

TEST_F(UtHardwareMonitor, WhenReportOverheatingAlarmIsCalled_ThenLogOverheatingAlarmToConsole) {
    int output = hardware_monitor.hwm_function();

    EXPECT_EQ(output, OVERHEATING);
}

TEST_F(UtHardwareMonitor, WhenReportPulsibleAlarmIsCalled_ThenLogPlausibleAlarmToConsole) {
    int output = hardware_monitor.hwm_function();

    EXPECT_EQ(output, PLAUSIBLE);
}