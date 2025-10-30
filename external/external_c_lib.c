#include "external_c_lib.h"

static int temp = 1;
const int num_sensor = 5;
static int sensor_temperatures[] = {0, 0, 0, 0, 0};

int read_raw_temp(int sensor_id) {
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

void reset_sensor() {
    for(int i = 0; i < num_sensor; i++)
    {
        sensor_temperatures[i] = 0;
    }
}
