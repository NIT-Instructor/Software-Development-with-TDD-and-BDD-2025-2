#include "gtest/gtest.h"
#include "ut_thermal_reader.hpp"

constexpr int kDefaultValueForTemperature = 33;
constexpr int kRawTemperatureStubValue = 42;

// User Story 3.2: Implement MockFilter Class
TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalled_ThenItShouldReturnDefaultValueForTemperature)
{
    EXPECT_CALL(mock_filter_, FilterData()).WillOnce(::testing::Return(kDefaultValueForTemperature));
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

// User Story 3.3: Verify Behavior of ThermalReader with MockFilter
TEST_F(UtThermalReader, WhenReadReadFilteredTemperatureIsCalled_ThenMockFilterFilterDataShouldreturnTheValueWeProvidedThroughTheMock)
{
    EXPECT_CALL(mock_filter_, FilterData()).WillOnce(::testing::Return(kRawTemperatureStubValue));
    auto return_value = temperature_reader_->ReadFilteredTemperature();
    EXPECT_EQ(return_value, kRawTemperatureStubValue);
}

TEST_F(UtThermalReader, WhenReadReadFilteredTemperatureIsCalledTwiceWithRepeatlyImput_ThenMockFilterFilterDataShouldreturnTheValueWeProvidedThroughTheMockAllTheTimes)
{
    EXPECT_CALL(mock_filter_, FilterData()).Times(3).WillRepeatedly(::testing::Return(kRawTemperatureStubValue));
    auto return_value1 = temperature_reader_->ReadFilteredTemperature();
    auto return_value2 = temperature_reader_->ReadFilteredTemperature();
    auto return_value3 = temperature_reader_->ReadFilteredTemperature();

    EXPECT_EQ(return_value1, kRawTemperatureStubValue);
    EXPECT_EQ(return_value2, kRawTemperatureStubValue);
    EXPECT_EQ(return_value3, kRawTemperatureStubValue);
}

TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalledThreeTimes_ThenMockFilterDataShouldReturnDifferentValuesEachTime)
{
    EXPECT_CALL(mock_filter_, FilterData())
        .Times(3)
        .WillOnce(::testing::Return(10))
        .WillOnce(::testing::Return(20))
        .WillOnce(::testing::Return(30));

    auto return_value1 = temperature_reader_->ReadFilteredTemperature();
    auto return_value2 = temperature_reader_->ReadFilteredTemperature();
    auto return_value3 = temperature_reader_->ReadFilteredTemperature();

    EXPECT_EQ(return_value1, 10);
    EXPECT_EQ(return_value2, 20);
    EXPECT_EQ(return_value3, 30);
}