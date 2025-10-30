#pragma once
#include <gmock/gmock.h>
#include "system_alarm_handler.hpp"


class MockSystemAlarmHandler : public SystemAlarmHandler {
public:
    MOCK_METHOD(void, ReportOverheating, (), (override));
    MOCK_METHOD(void, ReportUnderheating, (), (override));
};