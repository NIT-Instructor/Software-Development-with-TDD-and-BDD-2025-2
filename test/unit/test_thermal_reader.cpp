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

// User Story 3.3: Validate ThermalSensor Interaction Using MockFilter

TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsInvoked_ThenMockFilterShouldReturnThePresetStubValue)
{
    EXPECT_CALL(mockFilter_, FilterData()).WillOnce(::testing::Return(kRawTemperatureStubValue));
    auto return_value = temperatureReader_->ReadFilteredTemperature();
    EXPECT_EQ(return_value, kRawTemperatureStubValue);
}

TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalledMultipleTimes_ThenMockFilterShouldReturnTheSameStubValueEachTime)
{
    EXPECT_CALL(mockFilter_, FilterData()).Times(3).WillRepeatedly(::testing::Return(kRawTemperatureStubValue));

    auto return_value1 = temperatureReader_->ReadFilteredTemperature();
    auto return_value2 = temperatureReader_->ReadFilteredTemperature();
    auto return_value3 = temperatureReader_->ReadFilteredTemperature();

    EXPECT_EQ(return_value1, kRawTemperatureStubValue);
    EXPECT_EQ(return_value2, kRawTemperatureStubValue);
    EXPECT_EQ(return_value3, kRawTemperatureStubValue);
}

TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalledSequentially_ThenMockFilterShouldReturnDifferentStubValuesOnEachInvocation)
{
    EXPECT_CALL(mockFilter_, FilterData())
        .Times(3)
        .WillOnce(::testing::Return(6))
        .WillOnce(::testing::Return(12))
        .WillOnce(::testing::Return(18));

    auto return_value1 = temperatureReader_->ReadFilteredTemperature();
    auto return_value2 = temperatureReader_->ReadFilteredTemperature();
    auto return_value3 = temperatureReader_->ReadFilteredTemperature();

    EXPECT_EQ(return_value1, 6);
    EXPECT_EQ(return_value2, 12);
    EXPECT_EQ(return_value3, 18);
}

// User Story 3.4: Validate ReadFilteredTemp() Behavior with MockFilter

TEST_F(UtThermalReader, WhenReadFilteredTemperatureReturnsMultipleNegativeValues_ThenItShouldMatchEachMockedResult)
{
    EXPECT_CALL(mockFilter_, FilterData())
        .Times(3)
        .WillOnce(::testing::Return(-3))
        .WillOnce(::testing::Return(-12))
        .WillOnce(::testing::Return(-45));

    auto return_value1 = temperatureReader_->ReadFilteredTemperature();
    auto return_value2 = temperatureReader_->ReadFilteredTemperature();
    auto return_value3 = temperatureReader_->ReadFilteredTemperature();

    EXPECT_EQ(return_value1, -3);
    EXPECT_EQ(return_value2, -12);
    EXPECT_EQ(return_value3, -45);
}