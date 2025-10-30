#include "../inc/hardware_monitor.hpp"
#include <chrono>
#include <iostream>

HardwareMonitor::HardwareMonitor(ThermalReader& reader, Codings& codings) : reader_(reader) , codings_(codings), last_update_time_(std::chrono::steady_clock::now()) {};
int HardwareMonitor::Update() {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_update_time_).count();
        int filtered_temp;
        bool minValue; 
        bool maxValue;
        if (elapsed >= kUpdateIntervalMs)
        {
            filtered_temp = reader_.UpdateCurrentTemp();
            last_update_time_ = now;
        }

        if (filtered_temp > codings_.GetMaxThreshold()) {
            std::cout << "[ALARM] Overheating! Temp = " << filtered_temp << " °C" << std::endl;

        } 
        else if (filtered_temp < codings_.GetMinThreshold()) {
            std::cout << "[ALARM] Underheating! Temp = " << filtered_temp << " °C" << std::endl;
        }

        return reader_.ReadFilteredTemperature();
};