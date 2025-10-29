#pragma once
#include "common.hpp"
#include "thermal_reader.hpp"
#include "codings.hpp"
#include "system_alarm_handler.hpp"

class HardwareMonitor
{
    public:
        HardwareMonitor(ThermalReader& thermal_reader, Codings& codings, SystemAlarmHandler& system_alarm_handler);
        bool updateFilterTemperatures(int new_value);
        int readFilteredTemperatures();
        bool checkProvidedCoding(int new_value);
    
    private:
        ThermalReader thermal_reader_;
        Codings       codings_;
        SystemAlarmHandler system_alarm_handler_;
};