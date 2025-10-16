#include "ut_filter.hpp"

UtFilter::UtFilter()
{
}

void UtFilter::InitializeBuffer(uint8_t i)
{
    filter_.buffer_.fill(i);
}

void UtFilter::SetUp()
{
    std::cout << "SetUp" << std::endl;
}