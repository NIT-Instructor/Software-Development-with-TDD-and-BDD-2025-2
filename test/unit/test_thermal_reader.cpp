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

// User Story 3.4: Test ReadFilteredTemperature Method
TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsNegative_ThenItShouldReturnNegativeValue)
{
    EXPECT_CALL(mock_filter_, FilterData()).WillOnce(::testing::Return(-15));
    auto return_value = temperature_reader_->ReadFilteredTemperature();
    EXPECT_EQ(return_value, -15);
}

TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsZero_ThenItShouldReturnZero)
{
    EXPECT_CALL(mock_filter_, FilterData()).WillOnce(::testing::Return(0));
    auto return_value = temperature_reader_->ReadFilteredTemperature();
    EXPECT_EQ(return_value, 0);
}

TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalledMultipleTimesWithMixedValues_ThenItShouldReturnEachValueInOrder)
{
    EXPECT_CALL(mock_filter_, FilterData())
        .Times(4)
        .WillOnce(::testing::Return(5))
        .WillOnce(::testing::Return(-7))
        .WillOnce(::testing::Return(10))
        .WillOnce(::testing::Return(-25));

    EXPECT_EQ(temperature_reader_->ReadFilteredTemperature(), 5);
    EXPECT_EQ(temperature_reader_->ReadFilteredTemperature(), -7);
    EXPECT_EQ(temperature_reader_->ReadFilteredTemperature(), 10);
    EXPECT_EQ(temperature_reader_->ReadFilteredTemperature(), -25);
}