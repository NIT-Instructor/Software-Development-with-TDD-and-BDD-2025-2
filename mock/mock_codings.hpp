#pragma once

#include <gmock/gmock.h>
#include "codings.hpp"

class MockCodings : public Codings
{
  public:
    MockCodings()  = default;
    ~MockCodings() = default;

    MOCK_METHOD(int, GetMinTreashold, ());
    MOCK_METHOD(int, GetMaxTreashold, ());
    MOCK_METHOD(bool, AreCodingsPlausable, ());
};