#pragma once

#include "raw_temp_facade.hpp"
#include <gmock/gmock.h>

class MockRawTempFacade : public RawTempFacade
{
  public:
    MockRawTempFacade()  = default;
    ~MockRawTempFacade() = default;

    MOCK_METHOD(int, ReadRawTemp, (), (override));
};  


