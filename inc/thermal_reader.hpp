#pragma once

#include "common.hpp"
#include "filter.hpp"
#include "raw_temp_facade.hpp"

class ThermalReader
{
  public:
    ThermalReader(Filter& filter, RawTempFacade& raw_temp_facade);

    MOCKABLE int  ReadFilteredTemperature();
    MOCKABLE bool UpdateCurrentTemp();

  PRIVATE : 
    Filter& filter_;
    RawTempFacade& raw_temp_facade_;

};
