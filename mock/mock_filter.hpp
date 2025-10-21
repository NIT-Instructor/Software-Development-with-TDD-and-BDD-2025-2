#pragma once

#include "filter.hpp"
#include <gmock/gmock.h>

class MockFilter : public Filter
{
  public:
    MOCK_METHOD0(FilterData, int());
    MOCK_METHOD1(UpdateFilterData, bool(int new_value));
};