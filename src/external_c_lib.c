#include "external_c_lib.h"

static int temp = 1;

int read_raw_temp() {
    temp += 1;
    return temp;
}
