#pragma once

#include <gmock/gmock.h>

#include "codings.hpp"

class MockCodings : public Codings
{
  public:
    MockCodings()  = default;
    ~MockCodings() = default;
    MOCK_METHOD(int, GetMinThreshold, (), (const, override));
    MOCK_METHOD(int, GetMaxThreshold, (), (const, override));
    MOCK_METHOD(bool, AreCodingsPlausable, (), (const, override));
};