#include "gtest/gtest.h"
#include "ut_system_alarm_handler.hpp"


TEST_F(UtSystemAlarmHandler, ReportOverheating_ReturnsExpectedMessage)
{
    std::string result = alarm_handler_.ReportOverheating();
    EXPECT_EQ(result, "[ALARM] Overheating detected!\n");
}

TEST_F(UtSystemAlarmHandler, ReportUnderheating_ReturnsExpectedMessage)
{
    std::string result = alarm_handler_.ReportUnderheating();
    EXPECT_EQ(result, "[ALARM] Underheating detected!\n");
}

TEST_F(UtSystemAlarmHandler, ReportUnderheating_ReturnsNotExpectedMessage)
{
    std::string result = alarm_handler_.ReportUnderheating();
    EXPECT_NE(result, "[ALARM] Underheating !\n");
}

TEST_F(UtSystemAlarmHandler, ReportOverheating_ReturnsNotExpectedMessage)
{
    std::string result = alarm_handler_.ReportOverheating();
    EXPECT_NE(result, "[ALARM] Overheating !\n");
}