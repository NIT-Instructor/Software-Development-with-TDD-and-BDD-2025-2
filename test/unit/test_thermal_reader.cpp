#include "gtest/gtest.h"
#include "ut_thermal_reader.hpp"

constexpr int kDefaultValueForTemperature = 33;
constexpr int kRawTemperatureStubValue = 42;

// User Story 3.2: Create a Mock Version of Filter

TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalled_ThenItShouldReturnMockValue33)
{
   ON_CALL(mockFilter_, FilterData()).WillByDefault(testing::Return(kDefaultValueForTemperature));

    auto return_value = temperatureReader_->ReadFilteredTemperature();
    EXPECT_EQ(return_value, kDefaultValueForTemperature);
}

TEST_F(UtThermalReader, WhenReadReadFilteredTemperatureIsCalledThreeTImes_ThenMockFilterFilterDataShouldBeCalledThreeTimes)
{
    EXPECT_CALL(mockFilter_, FilterData()).Times(3);

    temperatureReader_->ReadFilteredTemperature();
    temperatureReader_->ReadFilteredTemperature();
    temperatureReader_->ReadFilteredTemperature();
}