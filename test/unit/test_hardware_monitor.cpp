#include "ut_hardware_monitor.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

#define UNDERHEATING    1
#define OVERHEATING     2
#define NOT_PLAUSIBLE   3

TEST_F(UtHardwareMonitor, WhenReportUnderheatingAlarmIsCalled_ThenLogUnderheatingAlarmToConsole) {

    ON_CALL(mock_thermal_reader, ReadFilteredTemperature()).WillByDefault(testing::Return(-25));
    ON_CALL(mock_thermal_reader, UpdateCurrentTemp()).WillByDefault(testing::Return(true));
    ON_CALL(mock_codings, GetMaxThreshold()).WillByDefault(testing::Return(50));
    ON_CALL(mock_codings, GetMinThreshold()).WillByDefault(testing::Return(-5));
    ON_CALL(mock_codings, AreCodingsPlausable()).WillByDefault(testing::Return(true));

    int output = hardware_monitor.hwm_function();

    EXPECT_EQ(output, UNDERHEATING);
}

TEST_F(UtHardwareMonitor, WhenReportOverheatingAlarmIsCalled_ThenLogOverheatingAlarmToConsole) {

    ON_CALL(mock_thermal_reader, ReadFilteredTemperature()).WillByDefault(testing::Return(70));
    ON_CALL(mock_thermal_reader, UpdateCurrentTemp()).WillByDefault(testing::Return(true));
    ON_CALL(mock_codings, GetMaxThreshold()).WillByDefault(testing::Return(40));
    ON_CALL(mock_codings, GetMinThreshold()).WillByDefault(testing::Return(-10));
    ON_CALL(mock_codings, AreCodingsPlausable()).WillByDefault(testing::Return(true));

    int output = hardware_monitor.hwm_function();

    EXPECT_EQ(output, OVERHEATING);
}

TEST_F(UtHardwareMonitor, WhenReportPulsibleAlarmIsCalled_ThenLogPlausibleAlarmToConsole) {

    ON_CALL(mock_thermal_reader, ReadFilteredTemperature()).WillByDefault(testing::Return(3));
    ON_CALL(mock_thermal_reader, UpdateCurrentTemp()).WillByDefault(testing::Return(true));
    ON_CALL(mock_codings, GetMaxThreshold()).WillByDefault(testing::Return(80));
    ON_CALL(mock_codings, GetMinThreshold()).WillByDefault(testing::Return(-30));
    ON_CALL(mock_codings, AreCodingsPlausable()).WillByDefault(testing::Return(false));

    int output = hardware_monitor.hwm_function();

    EXPECT_EQ(output, NOT_PLAUSIBLE);
}