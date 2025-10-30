#pragma once

#include "common.hpp"

class SystemAlarmHandler {
  public:
    SystemAlarmHandler();

    MOCKABLE void ReportUnderheatingAlarm();
    MOCKABLE void ReportOverheatingAlarm();
    
};