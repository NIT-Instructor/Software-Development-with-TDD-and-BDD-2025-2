#pragma once

#include "system_alarm_handler.hpp"
#include <gmock/gmock.h>

class MockSystemAlarmHandler : public SystemAlarmHandler
{
  public:
    MockSystemAlarmHandler()  = default;
    ~MockSystemAlarmHandler() = default;

    MOCK_METHOD(void, ReportOverheatingAlarm, (int temperature), (const, override));
    MOCK_METHOD(void, ReportUnderheatingAlarm, (int temperature), (const, override));
};
