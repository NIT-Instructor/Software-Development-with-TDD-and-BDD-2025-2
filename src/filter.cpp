#include "filter.hpp"

Filter::Filter()
{
    buffer_.fill(0.0f);
}

void Filter::FillBufferWithValue(float value)
{
    for (auto &item : buffer_)
    {
        item = value;
    }
}

float Filter::FilterData()
{
    float sum = 0.0f;
    for (const auto &item : buffer_)
    {
        sum += item;
    }

    return sum / static_cast<float>(kBufferSize);
}
