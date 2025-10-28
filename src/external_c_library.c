#include "external_c_library.h"

static int sensor_temperatures[] = {0, 0, 0, 0, 0};

int read_raw_temp(int sensor_id)
{
    if (sensor_id < 1 || sensor_id > 5)
    {
        return -1;
    }

    sensor_temperatures[sensor_id - 1] += 1;
    if (sensor_temperatures[sensor_id - 1] > 120)
    {
        sensor_temperatures[sensor_id - 1] = 0;
    }
    return sensor_temperatures[sensor_id - 1];
}