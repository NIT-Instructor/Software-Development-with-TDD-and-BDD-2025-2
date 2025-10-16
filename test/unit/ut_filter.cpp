#include "ut_filter.hpp"

UtFilter::UtFilter() : filter_()
{
}

void UtFilter::InitializeBuffer(uint8_t i)
{
    for(uint8_t& element : filter_.buffer_)
    {
        element = i;
    }
}

void UtFilter::SetUp()
{
    std::cout << "SetUp" << std::endl;
}