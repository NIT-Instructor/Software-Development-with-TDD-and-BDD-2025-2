#pragma once

#include <gmock/gmock.h>
#include "filter.hpp"

class MockFilter : public Filter
{
public:
    MockFilter() = default;
    MOCK_METHOD(int, FilterData, (), (override));
};

