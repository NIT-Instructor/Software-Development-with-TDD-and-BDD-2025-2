#pragma once
#include "common.hpp"
#include "thermal_reader.hpp"
#include "codings.hpp"

class HardwareMonitor
{
    public:
        HardwareMonitor();
        bool updateFilterTemperatures(int new_value);
        int readFilteredTemperatures();
        bool checkProvidedCoding();
    
    private:
        ThermalReader thermal_reader_;
        Filter        filter_;
        RawTempFacade raw_temp_facade_;
        Codings       codings_;
};