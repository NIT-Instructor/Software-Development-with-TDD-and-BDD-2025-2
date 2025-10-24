#pragma once
#include "common.hpp"

class RawTempFacade
{
  public:
    MOCKABLE int ReadRawTemp(int sensor_id);
};
