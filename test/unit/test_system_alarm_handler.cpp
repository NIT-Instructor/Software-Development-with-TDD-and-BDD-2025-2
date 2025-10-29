#include "ut_system_alarm_handler.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

TEST_F(UtSystemAlarmHandler, WhenReportOverHeatingIsCalled_ThenLogUnderheatingAlarmToConsole ){
    testing::internal::CaptureStdout();
    system_alarm_handler_.ReportUnderheatingAlarm();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(output.c_str(), "Underheating alarm!\n");
}

TEST_F(UtSystemAlarmHandler, WhenReportOverHeatingIsCalled_ThenLogOverheatingAlarmToConsole ){
    testing::internal::CaptureStdout();
    system_alarm_handler_.ReportOverheatingAlarm();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(output.c_str(), "Overheating alarm!\n");
}

