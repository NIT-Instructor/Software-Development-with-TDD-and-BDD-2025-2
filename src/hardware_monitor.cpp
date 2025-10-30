#include "hardware_monitor.hpp"
#include <iostream>

HardwareMonitor::HardwareMonitor(ThermalReader& thermal_reader,
                                 Codings& codings,
                                 SystemAlarmHandler& alarm_handler)
    : thermal_reader_(thermal_reader)
    , codings_(codings)
    , alarm_handler_(alarm_handler)
    , is_monitoring_active_(false)
{
}

HardwareMonitor::~HardwareMonitor()
{
    StopMonitoring();
}

void HardwareMonitor::StartMonitoring()
{
    if (!is_monitoring_active_.load())
    {
        is_monitoring_active_ = true;
        monitoring_thread_ = std::thread(&HardwareMonitor::MonitoringLoop, this);
    }   
}

void HardwareMonitor::StopMonitoring()
{
    if (is_monitoring_active_.load())
    {
        is_monitoring_active_ = false;
        if (monitoring_thread_.joinable())
        {
            monitoring_thread_.join();
        }
    } 
}

bool HardwareMonitor::IsMonitoringActive() const
{
    return is_monitoring_active_.load();
}

void HardwareMonitor::CheckTemperature() const
{
    // Update filter with new temperature value
    thermal_reader_.UpdateCurrentTemp();

    // Read filtered temperature and check against thresholds
    int current_temp = thermal_reader_.ReadFilteredTemperature();
    int min_threshold = codings_.GetMinThreshold();
    int max_threshold = codings_.GetMaxThreshold();

    // Check for overheating
    if (current_temp > max_threshold)
    {
        alarm_handler_.ReportOverheatingAlarm(current_temp);
    }
    // Check for underheating
    else if (current_temp < min_threshold)
    {
        alarm_handler_.ReportUnderheatingAlarm(current_temp);
    }
}

bool HardwareMonitor::ValidateCodings() const
{
    return codings_.AreCodingsPlausable();
}

void HardwareMonitor::MonitoringLoop()
{
    while (is_monitoring_active_.load())
    {
        CheckTemperature();
        std::this_thread::sleep_for(std::chrono::milliseconds(kUpdateIntervalMs));
    }
}