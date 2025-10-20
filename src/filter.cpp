#include "filter.hpp"
#include <iostream>

Filter::Filter() : buffer_{0}, head_{-1}
{
}

bool Filter::UpdateFilterData(int newValue)
{
    head_          = (head_ + 1) % kBufferSize;
    buffer_[head_] = newValue;
    return true;
}

int Filter::FilterData()
{
    int sum = 0;
    for (int value : buffer_)
    {
        std::cout << value << " ";
        sum += value;
    }
    std::cout << std::endl;
    auto ret_value = sum / kBufferSize;

    std::cout << ret_value << std::endl;
    return ret_value;
}
