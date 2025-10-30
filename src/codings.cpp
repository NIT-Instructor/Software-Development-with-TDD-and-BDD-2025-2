#include "codings.hpp"

Codings::Codings(int min_treashold, int max_treashold)
    : min_treashold_(min_treashold), max_treashold_(max_treashold) {}

int Codings::GetMinTreashold()
{
    return min_treashold_;
}

int Codings::GetMaxTreashold()
{
    return max_treashold_;
}

bool Codings::AreCodingsPlausable()
{
    return (min_treashold_ >= MIN_ALLOWED_TREASHOLD) && (max_treashold_ <= MAX_ALLOWED_TREASHOLD) 
        && (min_treashold_ < max_treashold_);
}