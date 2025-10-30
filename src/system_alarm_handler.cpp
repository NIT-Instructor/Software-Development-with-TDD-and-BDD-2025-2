#include "system_alarm_handler.hpp"
#include <iostream>

SystemAlarmHandler::SystemAlarmHandler() {}

void SystemAlarmHandler::ReportUnderheatingAlarm(){
    std::cout << "Underheating alarm!\n";
}

void SystemAlarmHandler::ReportOverheatingAlarm(){
    std::cout << "Overheating alarm!\n";
}
