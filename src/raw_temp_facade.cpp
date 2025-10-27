extern "C" {
    #include "external_c_lib.h"
}
#include "raw_temp_facade.hpp"

int RawTempFacade::ReadRawTemp(int sensor_id)
{
    return read_raw_temp(sensor_id);
}
