#include "system_alarm_handler.hpp"

void SystemAlarmHandler::ReportOverheatingAlarm()
{
    std::cout << "Overheating alarm reported." << std::endl;
}

void SystemAlarmHandler::ReportUnderheatingAlarm()
{
    std::cout << "Underheating alarm reported." << std::endl;
}