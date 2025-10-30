#include "../inc/hardware_monitor.hpp"

HardwareMonitor::HardwareMonitor(ThermalReader& reader) : reader_(reader) {};
void HardwareMonitor::Update() {};