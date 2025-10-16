#include "ut_filter.hpp"

UtFilter::UtFilter() : filter_()
{
}

void UtFilter::InitializeBuffer(uint8_t i)
{
    for(int j = 0; j < filter_.buffer_.size(); j++) {
        filter_.buffer_[j] = i;
    }
}

void UtFilter::SetUp()
{
    std::cout << "SetUp" << std::endl;
}