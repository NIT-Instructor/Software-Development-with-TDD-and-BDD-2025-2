#include "codings.hpp"

Codings::Codings() {};

int Codings::GetMinThreshold() {
    return min_threshold_;
}

int Codings::GetMaxThreshold() {
    return max_threshold_;
}

bool Codings::AreCodingsPlausible() {
    return (min_threshold_ >= MINIMUM_THRESHOLD) && (max_threshold_ <= MAXIMUM_THRESHOLD);
}

void Codings::SetMinThreshold(int value) {
    min_threshold_ = value;
}

void Codings::SetMaxThreshold(int value) {
    max_threshold_ = value;
}