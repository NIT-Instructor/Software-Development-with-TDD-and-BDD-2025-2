#pragma once
#include "common.hpp"

// Adapter class for interfacing with C library function
class RawTempFacade {
public:
    MOCKABLE int ReadRawTemp() const;
    MOCKABLE ~RawTempFacade() = default;
};
