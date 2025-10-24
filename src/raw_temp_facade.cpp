#include "raw_temp_facade.hpp"
extern "C" {
    #include "external_c_lib.h"
}

// Placeholder implementation for adapter
int RawTempFacade::ReadRawTemp() {
    // Students will call the actual C function, e.g., read_raw_temp() here
    int result = read_raw_temp();
    return result;  // Placeholder return value
}
