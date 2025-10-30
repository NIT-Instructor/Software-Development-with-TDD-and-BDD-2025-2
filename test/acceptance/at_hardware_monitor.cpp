#include "at_hardware_monitor.hpp"

AtHardwareMonitor::AtHardwareMonitor() 
    : codings_(0, 50),
      theremal_reader_(filter_, raw_temp_facade_),
      hardware_monitor_(theremal_reader_, codings_, system_alarm_handler_)
{}