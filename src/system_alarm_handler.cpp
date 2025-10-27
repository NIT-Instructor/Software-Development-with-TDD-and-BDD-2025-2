#include "system_alarm_handler.hpp"
#include <iostream>


void SystemAlarmHandler::ReportOverheatingAlarm(int temperature) const
{
    std::cout << "ALARM: Overheating detected! Temperature: " << temperature << "°C" << std::endl;
}

void SystemAlarmHandler::ReportUnderheatingAlarm(int temperature) const
{
    std::cout << "ALARM: Underheating detected! Temperature: " << temperature << "°C" << std::endl;
}