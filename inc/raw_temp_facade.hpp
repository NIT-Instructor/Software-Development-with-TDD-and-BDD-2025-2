#pragma once
#include "common.hpp"

// Adapter class for interfacing with C library function
class RawTempFacade {
public:
    MOCKABLE int ReadRawTemp();  // Students will implement this method using the C library function

    // Destructor to be virtual for mockability
    MOCKABLE ~RawTempFacade() = default;
};

// Students will need to wrap the C function "read_raw_temp()" from the C library in this class.