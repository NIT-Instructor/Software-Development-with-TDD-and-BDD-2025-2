#pragma once

#include "common.hpp"
#include "filter.hpp"
#include "raw_temp_facade.hpp"

class ThermalReader
{
  public:
    static constexpr int kDefaultMinThreshold = -30;
    static constexpr int kDefaultMaxThreshold = 60;

    ThermalReader(Filter& filter, RawTempFacade& raw_temp_facade,
                  int min_threshold = kDefaultMinThreshold,
                  int max_threshold = kDefaultMaxThreshold);
    virtual ~ThermalReader() = default;

    MOCKABLE int  ReadFilteredTemperature() const;
    MOCKABLE bool UpdateCurrentTemp();

  PRIVATE : 
    Filter& filter_;
    RawTempFacade&    raw_temp_facade_;
    int               min_threshold_;
    int               max_threshold_;
};