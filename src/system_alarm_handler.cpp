#include "system_alarm_handler.hpp"


    SystemAlarmHandler:: ~SystemAlarmHandler() = default;

    string SystemAlarmHandler::ReportOverheating()
    {
         return "[ALARM] Overheating detected!\n";
    }

    string SystemAlarmHandler::ReportUnderheating()
    {
         return "[ALARM] Underheating detected!\n";
    }

