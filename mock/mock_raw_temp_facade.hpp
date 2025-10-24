#pragma once

#include "raw_temp_facade.hpp"
#include <gmock/gmock.h>

// Students should create a mock class for RawTempFacade.
// This class should mock the ReadRawTemp method using GoogleMock.

class MockRawTempFacade: public RawTempFacade{
    public:
        MOCK_METHOD(int, ReadRawTemp, (), (override));
};