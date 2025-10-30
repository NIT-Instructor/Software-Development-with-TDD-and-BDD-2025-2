#include "system_alarm_handler.hpp"

void SystemAlarmHandler::ReportOverheatingAlarm()
{
    ++overheat_alarm_counter_;
    std::cout << "Overheating alarm reported." << overheat_alarm_counter_ << std::endl;
}

void SystemAlarmHandler::ReportUnderheatingAlarm()
{
    ++underheat_alarm_counter_;
    std::cout << "Underheating alarm reported." << underheat_alarm_counter_ << std::endl;
}