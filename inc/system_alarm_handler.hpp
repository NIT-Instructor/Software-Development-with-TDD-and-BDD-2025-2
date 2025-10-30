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

    int GetUnderheatAlarmCount() const { return underheat_alarm_counter_; }
    int GetOverheatAlarmCount() const { return overheat_alarm_counter_; }

private:
    int underheat_alarm_counter_ = 0;
    int overheat_alarm_counter_ = 0;
};