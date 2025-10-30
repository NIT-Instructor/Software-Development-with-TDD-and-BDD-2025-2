#include "hardware_monitor.hpp"
#include <thread>
#include <chrono>
#include <iostream>

HardwareMonitor::HardwareMonitor(ThermalReader& thermal_reader_, Codings& codings_, SystemAlarmHandler& system_alarm_handler_)
    : thermal_reader(thermal_reader_),
      codings(codings_),
      system_alarm_handler(system_alarm_handler_) {}

int HardwareMonitor::hwm_function()
{
    using Monitoring::SystemStatus;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    thermal_reader.UpdateCurrentTemp();
    const int temperature = thermal_reader.ReadFilteredTemperature();

    SystemStatus status = SystemStatus::Normal;

    if (!codings.AreCodingsPlausible())
    {
        std::cout << "[Warning] Codings are not plausible — invalid thresholds." << std::endl;
        status = SystemStatus::NotPlausible;
    }
    else if (temperature < codings.GetMinThreshold())
    {
        system_alarm_handler.ReportUnderheatingAlarm();
        status = SystemStatus::Underheating;
    }
    else if (temperature > codings.GetMaxThreshold())
    {
        system_alarm_handler.ReportOverheatingAlarm();
        status = SystemStatus::Overheating;
    }

    return status;
}