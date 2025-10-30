#include "ut_hardware_monitor.hpp"

UtHardwareMonitor::UtHardwareMonitor() : mock_filter_(), mock_raw_temp_facade_(), mock_temperature_reader_(mock_filter_, mock_raw_temp_facade_), hardware_monitor_(mock_temperature_reader_)
{};