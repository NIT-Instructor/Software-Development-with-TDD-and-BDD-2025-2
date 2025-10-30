#include "hardware_monitor.hpp"

HardwareMonitor::HardwareMonitor(ThermalReader& thermal_reader, Codings& codings, SystemAlarmHandler& system_alarm_handler) 
    : thermal_reader_(thermal_reader), 
    codings_(codings), 
    system_alarm_handler_(system_alarm_handler) {}

void HardwareMonitor::checkProvidedCoding(int new_value)
{
    if (codings_.AreCodingsPlausable())
    {
        if (new_value < codings_.GetMinTreashold())
        {
            system_alarm_handler_.ReportUnderheatingAlarm();
        }
        else if (new_value > codings_.GetMaxTreashold())
        {
            system_alarm_handler_.ReportOverheatingAlarm();
        }
    }
}

void HardwareMonitor::start()
{
    bool expected = false;
    if (!monitor_running_.compare_exchange_strong(expected, true)) 
    {
        return;
    }

    monitor_thread_ = std::thread([this]() {
        while (monitor_running_.load()) {
            thermal_reader_.UpdateCurrentTemp();
            int filtered_temp = thermal_reader_.ReadFilteredTemperature();
            checkProvidedCoding(filtered_temp);
            std::this_thread::sleep_for(std::chrono::milliseconds(monitor_period_ms_));
        }
    });
}

void HardwareMonitor::stop()
{
    monitor_running_.store(false);
    if (monitor_thread_.joinable()) 
    {
        monitor_thread_.join();
    }
}