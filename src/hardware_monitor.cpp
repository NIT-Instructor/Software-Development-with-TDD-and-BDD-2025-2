#include "hardware_monitor.hpp"

HardwareMonitor::HardwareMonitor(ThermalReader& thermal_reader,
                                 Codings& codings,
                                 SystemAlarmHandler& alarm_handler)
    : thermal_reader_(thermal_reader)
    , codings_(codings)
    , alarm_handler_(alarm_handler)
    , is_monitoring_active_(false)
{
}

void HardwareMonitor::StartMonitoring()
{
    is_monitoring_active_ = true;
}

void HardwareMonitor::StopMonitoring()
{
    is_monitoring_active_ = false;
}

bool HardwareMonitor::IsMonitoringActive() const
{
    return is_monitoring_active_;
}

void HardwareMonitor::CheckTemperature()
{
    int current_temp = thermal_reader_.ReadFilteredTemperature();

    // TBD
}

bool HardwareMonitor::ValidateCodings() const
{
    // TBD
    return false;
}