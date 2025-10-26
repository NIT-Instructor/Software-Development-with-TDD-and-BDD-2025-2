#pragma once
#include "common.hpp"

class RawTempFacade
{
  public:
    RawTempFacade()  = default;
    MOCKABLE ~RawTempFacade();

    MOCKABLE int ReadRawTemp(int sensor_id) const;
};
