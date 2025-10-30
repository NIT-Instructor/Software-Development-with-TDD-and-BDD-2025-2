#include "raw_temp_facade.hpp"
extern "C" {
    #include "external_c_lib.h"
}

RawTempFacade::~RawTempFacade() = default;

int RawTempFacade::ReadRawTemp(int sensor_id) const
{
    return read_raw_temp(sensor_id);
}

void RawTempFacade::ResetSensor()
{
    reset_sensor();
}
