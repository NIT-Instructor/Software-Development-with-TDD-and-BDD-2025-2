extern "C" {
    #include "external_c_library.h"
}
#include "raw_temp_facade.hpp"

RawTempFacade::RawTempFacade()
{
    reset_sensor_temperatures();
}

int RawTempFacade::ReadRawTemp(int sensor_id)
{
    return read_raw_temp(sensor_id);
}
