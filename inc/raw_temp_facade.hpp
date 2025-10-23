#pragma once
#include "common.hpp"

class RawTempFacade {
public:
    MOCKABLE int ReadRawTemp();
    MOCKABLE ~RawTempFacade() = default;
};