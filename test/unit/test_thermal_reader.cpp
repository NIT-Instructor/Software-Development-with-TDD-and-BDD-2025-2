#include "gtest/gtest.h"
#include "ut_thermal_reader.hpp"

constexpr int kDefaultValueForTemperature = 33;
constexpr int kRawTemperatureStubValue = 42;

// User Story 3.1: Inject Mock Filter into ThermalReader
TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalled_ThenItShouldReturnMockValue33)
{
    ON_CALL(mock_filter_, FilterData()).WillByDefault(testing::Return(kDefaultValueForTemperature));

    auto return_value = temperature_reader_.ReadFilteredTemperature();
    EXPECT_EQ(return_value, kDefaultValueForTemperature);
}

// Use EXPECT_CALL with WillOnce to return a specific value for a single call
TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalled_ThenWillOnceReturn)
{
    EXPECT_CALL(mock_filter_, FilterData()).WillOnce(testing::Return(kRawTemperatureStubValue));

    auto return_value = temperature_reader_.ReadFilteredTemperature();
    EXPECT_EQ(return_value, kRawTemperatureStubValue);
}

// Use EXPECT_CALL with WillRepeatedly to always return the same value
TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalled_MultipleTimes_WillRepeatedlyReturn)
{
    EXPECT_CALL(mock_filter_, FilterData()).WillRepeatedly(testing::Return(kDefaultValueForTemperature));

    auto first = temperature_reader_.ReadFilteredTemperature();
    auto second = temperature_reader_.ReadFilteredTemperature();
    EXPECT_EQ(first, kDefaultValueForTemperature);
    EXPECT_EQ(second, kDefaultValueForTemperature);
}

// Sequence of returns using WillOnce chained calls
TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalled_ThenReturnSequence)
{
    EXPECT_CALL(mock_filter_, FilterData())
        .WillOnce(testing::Return(10))
        .WillOnce(testing::Return(20));

    EXPECT_EQ(temperature_reader_.ReadFilteredTemperature(), 10);
    EXPECT_EQ(temperature_reader_.ReadFilteredTemperature(), 20);
}
