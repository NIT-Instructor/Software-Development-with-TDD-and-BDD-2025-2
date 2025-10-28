#pragma once
#include "common.hpp"

class RawTempFacade
{
  public:
    RawTempFacade()  = default;
    MOCKABLE ~RawTempFacade(); // is not intended to be used polymorphically in production,
                               //so its destructor only needs to be virtual during testing
                               // to allow mocks (MOCK_ENABLE).

    MOCKABLE int ReadRawTemp(int sensor_id) const;
};
