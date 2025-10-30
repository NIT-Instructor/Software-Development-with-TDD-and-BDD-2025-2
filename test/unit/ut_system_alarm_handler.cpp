
#include "ut_system_alarm_handler.hpp"

UtSystemAlarmHandler::UtSystemAlarmHandler() : mock_filter_(), mock_raw_temp_facade_(), mock_temperature_reader_(mock_filter_, mock_raw_temp_facade_), hardware_monitor_(mock_temperature_reader_, codings_), codings_(), alarm_handler_()
{};