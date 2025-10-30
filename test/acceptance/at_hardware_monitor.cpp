#include "at_hardware_monitor.hpp"

AtHardwareMonitor::AtHardwareMonitor()
    : filter_(),
      raw_temp_facade_(),
      theremal_reader_(filter_, raw_temp_facade_),
      hardware_monitor_(theremal_reader_, codings_),
      codings_()
{
}