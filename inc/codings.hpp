#pragma once

#include "common.hpp"

#define MIN_ALLOWED_TREASHOLD 0
#define MAX_ALLOWED_TREASHOLD 120

class Codings
{
    public:
        Codings(int min_treashold = MIN_ALLOWED_TREASHOLD, int max_treashold = MAX_ALLOWED_TREASHOLD);
        MOCKABLE bool AreCodingsPlausable();
        MOCKABLE int GetMinTreashold();
        MOCKABLE int GetMaxTreashold();

    private:
        int min_treashold_{MIN_ALLOWED_TREASHOLD};
        int max_treashold_{MAX_ALLOWED_TREASHOLD};
};