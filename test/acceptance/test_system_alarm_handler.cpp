#include "at_system_alarm_handler.hpp"

constexpr bool kOverheating = true;
constexpr bool kUnderheating = false;

struct SystemAlarmConditions
{
    bool overheating;
    std::string alarm_message;
};

static const SystemAlarmConditions kSystemAlarmConditions[] = {
    {kOverheating,   "Overheating alarm!\n"},
    {kUnderheating,  "Underheating alarm!\n"}
};

class FixtureSystemAlarmHandler : public AtSystemAlarmHandler, public ::testing::WithParamInterface<SystemAlarmConditions>
{
};

INSTANTIATE_TEST_SUITE_P(SystemAlarmSuite, FixtureSystemAlarmHandler, ::testing::ValuesIn(kSystemAlarmConditions));

TEST_P(FixtureSystemAlarmHandler, ReportsCorrectAlarmMessage)
{
    testing::internal::CaptureStdout();
    if(GetParam().overheating) {
        system_alarm_handler_.ReportOverheatingAlarm();
    } else {
        system_alarm_handler_.ReportUnderheatingAlarm();
    }
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(GetParam().alarm_message, output.c_str());
}