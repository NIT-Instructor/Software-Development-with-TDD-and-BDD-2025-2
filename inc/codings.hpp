#pragma once

#include "common.hpp"

class Codings
{
    public:
        Codings();
        bool AreCodingsPlausable(int temperature_value);
    PRIVATE :
        MOCKABLE int GetMinTreashold();
        MOCKABLE int GetMaxTreashold();
};