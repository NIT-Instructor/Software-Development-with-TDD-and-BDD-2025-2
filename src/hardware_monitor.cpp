#include "hardware_monitor.hpp"

HardwareMonitor::HardwareMonitor(ThermalReader& thermal_reader_, Codings& codings_, SystemAlarmHandler& system_alarm_handler_)
    : thermal_reader(thermal_reader_),
      codings(codings_),
      system_alarm_handler(system_alarm_handler_) {}

int HardwareMonitor::hwm_function() {
    return 0;
}