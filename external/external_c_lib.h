#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Declaration of the C library function to read raw temperature
int read_raw_temp(int sensor_id);
void reset_sensor();

#ifdef __cplusplus
}
#endif
