#include "filter.hpp"

Filter::Filter() : buffer_{} {}

float Filter::FilterData()
{
    float sum = 0;
    for(int i = 0; i < buffer_.size(); i++) {
        sum += buffer_[i];
    }
    return sum / buffer_.size();
}
