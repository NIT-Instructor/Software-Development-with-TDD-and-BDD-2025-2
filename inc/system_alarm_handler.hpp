#pragma once

#include "common.hpp"

class SystemAlarmHandler
{
public:
    SystemAlarmHandler() = default;
    virtual ~SystemAlarmHandler() = default;

    MOCKABLE void ReportOverheatingAlarm(int temperature) const;
    MOCKABLE void ReportUnderheatingAlarm(int temperature) const;
};