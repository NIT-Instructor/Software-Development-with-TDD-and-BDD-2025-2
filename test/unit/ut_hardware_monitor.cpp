#include "ut_hardware_monitor.hpp"

UtHardwareMonitor::UtHardwareMonitor()
    : mock_codings_(),
    mock_system_alarm_handler_(),
    mock_filter_(), 
    mock_raw_temp_facade_(), 
    mock_thermal_reader_(mock_filter_,mock_raw_temp_facade_), 
    hardware_monitor_(mock_thermal_reader_, mock_codings_, mock_system_alarm_handler_){}