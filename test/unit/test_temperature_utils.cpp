#include "temperature_utils.hpp"
#include <gtest/gtest.h>

// User Story 1.1: Convert Celsius to Kelvin
/*TEST(TemperatureUtils, WhenCelsiusToKelvinIsCalledWith0_Then273ShouldBeReturned)
{
    EXPECT_EQ(CelsiusToKelvin(0), 273);
}*/
// TODO: Students will add more test cases for other temperature conversions
// 1.
TEST(TemperatureUtils, WhenCelsiusToKelvinIsCalledWith0_Then273ShouldBeReturned) {
 // Test data: 0°C should convert to 273 K
 double celsius = 0.0;
 double expected = 273.0;

 // Call function under test
 double result = CelsiusToKelvin(celsius);

 // Assert expected result
 EXPECT_EQ(expected, result);
}
// Build and run: Verify the test FAILS
// This failure is good - it confirms your test works!


// Test case for decigrade conversion
//2.
TEST(TemperatureUtils, WhenCelsiusDecigradesToCelsiusIsCalledWith100_Then10ShouldBeReturned) {
 // Test data: 100 decigrades = 10°C
 double decigrades = 100.0;
 double expected = 10.0;

 // Call function under test
 double result = CelsiusDecigradeToCelsius(decigrades);

 // Assert expected result
 EXPECT_EQ(expected, result);
}
// Run test and verify it FAILS
// You know the drill now!

// Test case for inverse conversion
//3.
/*TEST(TemperatureUtils, WhenKelvinToCelsiusIsCalledWith273_Then0ShouldBeReturned) {
 // Test data: 273 K = 0°C
 double kelvin = 273.0;
 double expected = 0.0;

 // Call function under test
 double result = KelvinToCelsius(kelvin);

 // Assert expected result
 EXPECT_EQ(expected, result);
}*/
// Run and verify failure
// This is your third RED-GREEN-REFACTOR cycle
TEST(TemperatureUtils, WhenKelvinToCelsiusIsCalledWith273_Then0ShouldBeReturned) {
 // Test data: 273 K = 0°C
 double kelvin = 273.0;
 double expected = 0.0;

 // Call function under test
 double result = KelvinToCelsius(kelvin);

 // Assert expected result
 EXPECT_EQ(expected, result);
}