#include "filter.hpp"

Filter::Filter()
{
    buffer_.fill(0);
}

int Filter::FilterData() {
    int average = 0;
    for (auto it : buffer_)
    {
        average += it;
    }
    return average / buffer_.size();
}