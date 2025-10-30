#include "ut_hardware_monitor.hpp"

UtHardwareMonitor::UtHardwareMonitor() : mock_thermal_reader(mock_filter, mock_raw_temp_facade), mock_codings(), hardware_monitor(mock_thermal_reader, mock_codings, mock_system_alarm) {}