#include "codings.hpp"

Codings::Codings() : min_threshold(kDefaultMinThreshold), max_threshold(kDefaultMaxThreshold)
{
}

int Codings::GetMinThreshold() const
{
    return min_threshold;
}

int Codings::GetMaxThreshold() const
{
    return max_threshold;
}

bool Codings::AreCodingsPlausable() const
{
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

void Codings::SetMaxThreshold(int max)
{
    max_threshold = max;
}

void Codings::SetMinThreshold(int min)
{
    min_threshold = min;
}
