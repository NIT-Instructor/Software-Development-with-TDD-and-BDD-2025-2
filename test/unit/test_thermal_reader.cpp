#include "gtest/gtest.h"
#include "ut_thermal_reader.hpp"

constexpr int kDefaultValueForTemperature = 33;
constexpr int kRawTemperatureStubValue = 42;

// User Story 3.2: Implement MockFilter Class
TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalled_ThenItShouldReturnDefaultValueForTemperature)
{
    auto return_value = temperature_reader_->ReadFilteredTemperature();
    EXPECT_EQ(return_value, kDefaultValueForTemperature);
}

TEST_F(UtThermalReader, WhenReadReadFilteredTemperatureIsCalled_ThenMockFilterFilterDataShouldBeCalledOnce)
{
    EXPECT_CALL(mock_filter_, FilterData()).Times(1);
    temperature_reader_->ReadFilteredTemperature();
}

TEST_F(UtThermalReader, WhenReadReadFilteredTemperatureIsCalledTwice_ThenMockFilterFilterDataShouldBeCalledTwice)
{
    EXPECT_CALL(mock_filter_, FilterData()).Times(2);
    temperature_reader_->ReadFilteredTemperature();
    temperature_reader_->ReadFilteredTemperature();
}