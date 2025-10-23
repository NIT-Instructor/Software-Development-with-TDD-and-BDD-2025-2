#pragma once

#include "raw_temp_facade.hpp"
#include <gmock/gmock.h>

class MockRawTempFacade : public RawTempFacade
{
  public:
    MOCK_METHOD(int, ReadRawTemp, (int), (override));
};
