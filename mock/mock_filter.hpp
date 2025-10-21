#pragma once

#include <gmock/gmock.h>
#include "filter.hpp"

class MockFilter : public Filter
{
  public:
    MockFilter()  = default;
    ~MockFilter() = default;

    MOCK_METHOD(int, FilterData, (), (const, override));
    MOCK_METHOD(bool, UpdateFilterData, (int), (override));
};

