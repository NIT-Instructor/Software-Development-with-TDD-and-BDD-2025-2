#pragma once

#include "filter.hpp"
#include <gmock/gmock.h>

class MockFilter : public Filter
{

  // Mock FilterData and UpdateFilterData
  // MOCK_METHOD(<return type>, <MethodName>, (input type), (override));
};
