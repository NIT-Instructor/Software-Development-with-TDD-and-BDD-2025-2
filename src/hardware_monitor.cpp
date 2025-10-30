#include "../inc/hardware_monitor.hpp"
#include <chrono>
#include <iostream>

using namespace std;

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
            cout << "FILTERED TEMP" << filtered_temp << endl;
            last_update_time_ = now;
            return reader_.ReadFilteredTemperature();
        } else { 
            return 0;
        }

};