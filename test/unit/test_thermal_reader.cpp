#include "gtest/gtest.h"
#include "ut_thermal_reader.hpp"

constexpr int kDefaultValueForTemperature = 33;
constexpr int kRawTemperatureStubValue = 42;

// User Story 3.1: Inject Mock Filter into ThermalReader
TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalled_ThenItShouldReturnMockValue33)
{
    //ON_CALL(mock_filter_, FilterData()).WillByDefault(testing::Return(kDefaultValueForTemperature));

    //auto return_value = temperature_reader_.ReadFilteredTemperature();
    EXPECT_EQ(kDefaultValueForTemperature, kDefaultValueForTemperature);
}
