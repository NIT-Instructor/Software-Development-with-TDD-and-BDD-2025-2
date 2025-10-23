#include "raw_temp_facade.hpp"
#include "external_c_lib.h"

int RawTempFacade::ReadRawTemp() {
    return read_raw_temp();
}
