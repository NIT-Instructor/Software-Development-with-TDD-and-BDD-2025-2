#pragma once

#include "common.hpp"
#include "filter.hpp"

class ThermalReader
{
public:
  ThermalReader(Filter &filter);

  int ReadFilteredTemperature();
  bool UpdateCurrentTemp();

  PRIVATE : Filter &filter_;
};