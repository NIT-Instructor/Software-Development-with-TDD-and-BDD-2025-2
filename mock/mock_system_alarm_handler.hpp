#pragma once

#include "system_alarm_handler.hpp"
#include <gmock/gmock.h>

class MockSystemAlarmHandler : public SystemAlarmHandler
{
  public:
    MOCK_METHOD(void, ReportOverheatingAlarm, ());
    MOCK_METHOD(void, ReportUnderheatingAlarm, ());
};