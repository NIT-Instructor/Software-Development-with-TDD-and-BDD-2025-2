#pragma once
#include "common.hpp"

class RawTempFacade
{
  public:
    RawTempFacade();
    MOCKABLE int ReadRawTemp(int sensor_id);
};
