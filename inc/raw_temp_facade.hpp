#pragma once
#include "common.hpp"

// Adapter class for interfacing with C library function
class RawTempFacade {
public:
    MOCKABLE int ReadRawTemp();
    MOCKABLE ~RawTempFacade() = default;
};
