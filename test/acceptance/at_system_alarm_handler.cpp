#include "at_system_alarm_handler.hpp"

 AtHardwareMonitorWithAlarm::AtHardwareMonitorWithAlarm()
      : filter_(),
      raw_temp_facade_(),
      theremal_reader_(filter_, raw_temp_facade_),
      codings_(),
      hardware_monitor_(theremal_reader_, codings_),
      mock_alarm_()
{
}
