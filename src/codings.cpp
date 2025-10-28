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
    int min_threshold = GetMinThreshold();
    int max_threshold = GetMaxThreshold();

    // Check if min threshold is less than max threshold
    if (min_threshold >= max_threshold)
    {
        return false;
    }

    // Check if thresholds are within reasonable limits
    // Typical temperature ranges: -273°C (absolute zero) to ~1000°C
    constexpr int kAbsoluteMinTemp = -273;
    constexpr int kAbsoluteMaxTemp = 1000;

    if (min_threshold < kAbsoluteMinTemp || max_threshold > kAbsoluteMaxTemp)
    {
        return false;
    }

    return true;
}