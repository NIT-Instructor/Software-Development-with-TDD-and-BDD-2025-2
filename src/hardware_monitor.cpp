#include "hardware_monitor.hpp"

HardwareMonitor::HardwareMonitor(ThermalReader& thermal_reader, Codings& codings, SystemAlarmHandler& system_alarm_handler) 
    : thermal_reader_(thermal_reader), 
    codings_(codings), 
    system_alarm_handler_(system_alarm_handler) {}

bool HardwareMonitor::updateFilterTemperatures(int new_value)
{
    return true;
}

int HardwareMonitor::readFilteredTemperatures()
{
    return 0;
}

bool HardwareMonitor::checkProvidedCoding(int new_value)
{
    if (!codings_.AreCodingsPlausable(new_value))
    {
        system_alarm_handler_.ReportOverheatingAlarm();
        return false;
    }
    return true;
}