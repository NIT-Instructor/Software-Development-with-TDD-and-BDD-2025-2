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
    return is_monitoring_active_;
}

void HardwareMonitor::CheckTemperature() const
{
    int current_temp = thermal_reader_.ReadFilteredTemperature();

    // TBD
}

bool HardwareMonitor::ValidateCodings() const
{
    // TBD
    return false;
}

void HardwareMonitor::MonitoringLoop()
{
    while (is_monitoring_active_.load())
    {
        CheckTemperature();
        std::this_thread::sleep_for(std::chrono::milliseconds(kUpdateIntervalMs));
    }
}