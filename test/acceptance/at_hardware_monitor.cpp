#include "at_hardware_monitor.hpp"

AtHardwareMonitor::AtHardwareMonitor() : thermal_reader(filter, raw_temp_facade), codings(), system_alarm_handler(), hardware_monitor(thermal_reader, codings, system_alarm_handler) {}