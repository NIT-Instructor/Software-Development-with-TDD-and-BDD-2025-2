#include "gtest/gtest.h"
#include "ut_thermal_reader.hpp"

constexpr int kDefaultValueForTemperature = 33;
constexpr int kRawTemperatureStubValue = 42;

// User Story 3.1: Inject Mock Filter into ThermalReader
TEST_F(UtThermalReader, WhenReadFilteredTemperatureIsCalled_ThenItShouldReturnValueFromFilterData)
{
    ON_CALL(mock_filter_, FilterData()).WillByDefault(testing::Return(kDefaultValueForTemperature));

    auto return_value = temperature_reader_.ReadFilteredTemperature();
    EXPECT_EQ(return_value, kDefaultValueForTemperature);
}

// User Story 3.2: Simulate Filter Failure in ThermalReader
TEST_F(UtThermalReader, WhenFilterFailureOccures_ThenThermalReaderShouldHandleErrorGracefully)
{
    ON_CALL(mock_filter_, FilterData()).WillByDefault(testing::Return(-1));

    auto result = temperature_reader_.ReadFilteredTemperature();
    EXPECT_EQ(result, -1);
}

// User Story 3.3: Verify Dependency Injection in ThermalReader
TEST_F(UtThermalReader, WhenUpdateCurrentTempOccurs_ThenUpdateFilterDataIsCalledWithReadRawTempValue)
{
    EXPECT_CALL(mock_filter_, UpdateFilterData(0)).WillOnce(testing::Return(true));

    auto result = temperature_reader_.UpdateCurrentTemp();
    EXPECT_TRUE(result);
}

// Exercise 4.1: Students should implement this test to verify the interaction between Filter and RawTempFacade.
// This test should simulate reading raw temperature and passing it to Filter's UpdateFilterData method.
// Students should use GoogleMock to mock the dependencies and validate that the interaction occurs as expected.
TEST_F(UtThermalReader, UpdateCurrentTemp_CorrectlyProcessesTemperatureData)
{
    // Students need to set up ON_CALL and EXPECT_CALL for the mocked dependencies
    // that simulate the interactions for processing temperature data.

    // Students should ensure the result is verified after the method call
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

// Scenario 1: ThermalReader updates average temperature when sensor values change
TEST_F(UtThermalReader, WhenSensorValuesChange_ThermalReaderProvidesUpdatedAverage)
{
    // Simulate Filter producing a different average when sensor value changes
    EXPECT_CALL(mock_filter_, FilterData())
        .WillOnce(testing::Return(20))
        .WillOnce(testing::Return(25));

    auto first = temperature_reader_.ReadFilteredTemperature();
    auto second = temperature_reader_.ReadFilteredTemperature();

    EXPECT_EQ(first, 20);
    EXPECT_EQ(second, 25);
    EXPECT_NE(first, second); // average should update when readings change
}

// Scenario 2: ThermalReader applies filtering to stabilize temperature readings
TEST_F(UtThermalReader, RapidFluctuations_ResultingAverageChangesGradually)
{
    // Simulate a rapid sequence of raw inputs and the filter returning a
    // smoothed sequence of averages (gradual change)
    EXPECT_CALL(mock_filter_, FilterData())
        .WillOnce(testing::Return(60))
        .WillOnce(testing::Return(60))
        .WillOnce(testing::Return(60))
        .WillOnce(testing::Return(61));

    std::array<int, 4> readings{};
    for (int i = 0; i < 4; ++i) {
        readings[i] = temperature_reader_.ReadFilteredTemperature();
    }

    // Verify the resulting averages change only gradually between consecutive readings
    for (int i = 1; i < 4; ++i) {
        EXPECT_LE(std::abs(readings[i] - readings[i - 1]), 1);
    }
}

// Scenario 3: ThermalReader ensures latest temperature is always available
TEST_F(UtThermalReader, WhenHardwareRequestsCurrentTemperature_ReturnsMostRecentFilteredValue)
{
    // Provide a sequence of filtered values; each ReadFilteredTemperature() call
    // should return the most recent filtered value (no stale caching)
    EXPECT_CALL(mock_filter_, FilterData())
        .WillOnce(testing::Return(15))
        .WillOnce(testing::Return(25))
        .WillOnce(testing::Return(35));

    EXPECT_EQ(temperature_reader_.ReadFilteredTemperature(), 15);
    EXPECT_EQ(temperature_reader_.ReadFilteredTemperature(), 25);
    EXPECT_EQ(temperature_reader_.ReadFilteredTemperature(), 35);
}
