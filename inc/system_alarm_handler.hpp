#pragma once
#include <iostream>
#include "common.hpp"

class SystemAlarmHandler
{
public:
    SystemAlarmHandler() = default;
    ~SystemAlarmHandler() = default;

    MOCKABLE void ReportOverheatingAlarm();
    MOCKABLE void ReportUnderheatingAlarm();
};