#include "../inc/hardware_monitor.hpp"
#include <chrono>

HardwareMonitor::HardwareMonitor(ThermalReader& reader) : reader_(reader) ,last_update_time_(std::chrono::steady_clock::now()) {};
void HardwareMonitor::Update() {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_update_time_).count();

        if (elapsed >= kUpdateIntervalMs)
        {
            reader_.UpdateCurrentTemp();
            last_update_time_ = now;
        }
};