#include "hardware_monitor.hpp"
#include <thread>
#include <chrono>
#include <iostream>

HardwareMonitor::HardwareMonitor(ThermalReader& thermal_reader_, Codings& codings_, SystemAlarmHandler& system_alarm_handler_)
    : thermal_reader(thermal_reader_),
      codings(codings_),
      system_alarm_handler(system_alarm_handler_) {}

int HardwareMonitor::hwm_function() {

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    thermal_reader.UpdateCurrentTemp();
    int readed_temperature = thermal_reader.ReadFilteredTemperature();

    if(codings.AreCodingsPlausable()){
        if(readed_temperature < codings.GetMinThreshold()){
            system_alarm_handler.ReportUnderheatingAlarm();
            return 1;
        }
        if(readed_temperature > codings.GetMaxThreshold()){
            system_alarm_handler.ReportOverheatingAlarm();
            return 2;
        }
    }
    else{
        std::cout << "[Warning] Codings are not plausible — invalid thresholds." << std::endl;
        return 3;
    }
    return 0;
}