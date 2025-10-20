#include "ut_filter.hpp"

UtFilter::UtFilter() : filter_()
{
}

void UtFilter::InitializeBuffer(uint8_t i)
{
    filter_.buffer_ = std::array<uint8_t, 9>{i, i, i, i, i, i, i, i, i};
}

void UtFilter::SetUp()
{
    std::cout << "SetUp" << std::endl;
}