#pragma once

#include "common.hpp"
#include "filter.hpp"
#include "raw_temp_facade.hpp"
#include "thermal_reader.hpp"

class HardwareMonitor
{
  public:
    HardwareMonitor(ThermalReader& reader);

    void Update();




  private : 
    ThermalReader &reader_;
};