#include "external_c_lib.h"

int temp = 1;

int read_raw_temp(void) {

    temp = temp + 1;

    return temp;
}