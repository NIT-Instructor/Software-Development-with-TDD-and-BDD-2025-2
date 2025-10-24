#pragma once

#include "common.hpp"
#include "filter.hpp"
#include "raw_temp_facade.hpp"

class ThermalReader
{
  public:
    ThermalReader(Filter& filter, RawTempFacade& rawTempFacade);

    MOCKABLE int  ReadFilteredTemperature();
    MOCKABLE bool UpdateCurrentTemp();

  PRIVATE : 
    Filter& filter_;
    RawTempFacade& rawTempFacade_;

};