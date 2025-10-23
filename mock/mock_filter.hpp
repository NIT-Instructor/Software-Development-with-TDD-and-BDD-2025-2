#pragma once

#include "filter.hpp"
#include <gmock/gmock.h>

class MockFilter : public Filter
{
  public:
    MockFilter()  = default;
    ~MockFilter() = default;

    MOCK_METHOD(int, FilterData, (), (override));
    MOCK_METHOD(bool, UpdateFilterData, (int), (override));
};
