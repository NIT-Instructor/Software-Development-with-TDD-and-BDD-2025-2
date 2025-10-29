#include "codings.hpp"

Codings::Codings() {}

int Codings::GetMinTreashold()
{
    return 0;
}

int Codings::GetMaxTreashold()
{
    return 100;
}

bool Codings::AreCodingsPlausable(int temperature_value)
{
    return true;
}