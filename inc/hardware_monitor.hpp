#pragma once

#include "system_alarm_handler.hpp"
#include "codings.hpp"
#include "thermal_reader.hpp"

class HardwareMonitor {

public:
    HardwareMonitor(ThermalReader&, Codings&,  SystemAlarmHandler&);
    int hwm_function();

PRIVATE:
    ThermalReader& thermal_reader;
    Codings& codings;
    SystemAlarmHandler& system_alarm_handler;

};