#include "hardware_monitor.hpp"

HardwareMonitor::HardwareMonitor() : thermal_reader_(filter_, raw_temp_facade_) {}

bool HardwareMonitor::updateFilterTemperatures(int new_value)
{
    return true;
}

int HardwareMonitor::readFilteredTemperatures()
{
    return 0;
}

bool HardwareMonitor::checkProvidedCoding()
{
    return true;
}