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

// User Story 4.1: Verify UpdateCurrentTemp Interaction with Filter and RawTempFacade
TEST_F(UtThermalReader, WhenUpdateCurrentTempOccurs_ThenTemperatureDataIsProcessed)
{
    ON_CALL(mock_raw_temp_facade_, ReadRawTemp(testing::_)).WillByDefault(testing::Return(kRawTemperatureStubValue));
    EXPECT_CALL(mock_filter_, UpdateFilterData(kRawTemperatureStubValue)).WillOnce(testing::Return(true));

    auto result = temperature_reader_.UpdateCurrentTemp();
    EXPECT_TRUE(result);
}
