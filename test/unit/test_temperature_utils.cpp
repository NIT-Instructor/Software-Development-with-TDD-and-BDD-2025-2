#include "temperature_utils.hpp"
#include <gtest/gtest.h>

// User Story 1.1: Convert Celsius to Kelvin
TEST(TemperatureUtils, WhenCelsiusToKelvinIsCalledWith0_Then273ShouldBeReturned)
{
    // Test data: 0°C should convert to 273 K
    double celsius = 0.0;
    double expected = 273.0;
    // Call function under test
    double result = CelsiusToKelvin(celsius);
    // Assert expected result
    EXPECT_EQ(expected, result);
}

TEST(TemperatureUtils, WhenCelsiusToKelvinIsCalledWith3_Then276ShouldBeReturned)
{
    // Test data: 3°C should convert to 276 K
    double celsius = 3.0;
    double expected = 276.0;
    // Call function under test
    double result = CelsiusToKelvin(celsius);
    // Assert expected result
    EXPECT_EQ(expected, result);
}

//User Story 1.2: Convert Celsius Decigrades to Celsius
TEST(TemperatureUtils, WhenCelsiusDecigradesToCelsiusIsCalledWith100_Then10ShouldBeReturned) {
    // Test data: 100 decigrades = 10°C
    double decigrades = 100.0;
    double expected = 10.0;
    // Call function under test
    double result = CelsiusDecigradeToCelsius(decigrades);
    // Assert expected result
    EXPECT_EQ(expected, result);
}

TEST(TemperatureUtils, WhenCelsiusDecigradesToCelsiusIsCalledWith330_Then33ShouldBeReturned) {
    // Test data: 330 decigrades = 33°C
    double decigrades = 330.0;
    double expected = 33.0;
    // Call function under test
    double result = CelsiusDecigradeToCelsius(decigrades);
    // Assert expected result
    EXPECT_EQ(expected, result);
}

//User Story 1.3: Convert Kelvin to Celsius
TEST(TemperatureUtils, WhenKelvinToCelsiusIsCalledWith273_Then0ShouldBeReturned) {
    // Test data: 273 K = 0°C
    double kelvin = 273.0;
    double expected = 0.0;
    // Call function under test
    double result = KelvinToCelsius(kelvin);
    // Assert expected result
    EXPECT_EQ(expected, result);
}

TEST(TemperatureUtils, WhenKelvinToCelsiusIsCalledWith280_Then7ShouldBeReturned) {
    // Test data: 280 K = 7°C
    double kelvin = 280.0;
    double expected = 7.0;
    // Call function under test
    double result = KelvinToCelsius(kelvin);
    // Assert expected result
    EXPECT_EQ(expected, result);
}
// TODO: Students will add more test cases for other temperature conversions