#include "codings.hpp"

Codings::Codings() {};
int Codings::GetMinThreshold() {
    return 0;
}
int Codings::GetMaxThreshold() {
    return 100;
}
bool Codings::AreCodingsPlausable() {
    return false;
}

void Codings::SetMinThreshold(int value){}
void Codings::SetMaxThreshold(int value){}