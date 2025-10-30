#include "../inc/codings.hpp"

Codings::Codings()
    : min_threshold_(10), max_threshold_(500) {}

float Codings::GetMinThreshold() const {
    return min_threshold_;
}

float Codings::GetMaxThreshold() const {
    return max_threshold_;
}

void Codings::SetMinThreshold(float value) {
    min_threshold_ = value;
}

void Codings::SetMaxThreshold(float value) {
    max_threshold_ = value;
}

bool Codings::CheckThresholds(float value) const {
    if (value < min_threshold_ | value > max_threshold_) {
        return true;
    }
}