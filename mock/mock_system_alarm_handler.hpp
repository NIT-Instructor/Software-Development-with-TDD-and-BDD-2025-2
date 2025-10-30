#pragma once

#include <gmock/gmock.h>

#include "system_alarm_handler.hpp"

class MockSystemAlarmHandler : public SystemAlarmHandler {
    public:
        MockSystemAlarmHandler() = default;
        ~MockSystemAlarmHandler() = default;
        MOCK_METHOD(void, ReportUnderheatingAlarm, (), (override));
        MOCK_METHOD(void, ReportOverheatingAlarm, (), (override));

};