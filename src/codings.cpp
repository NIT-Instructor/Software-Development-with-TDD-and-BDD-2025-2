#include "codings.hpp"

int Codings::GetMinThreshold() const
{
    return kDefaultMinThreshold;
}

int Codings::GetMaxThreshold() const
{
    return kDefaultMaxThreshold;
}

bool Codings::AreCodingsPlausable() const
{
    return true;  // TBD: implement actual plausibility check
}