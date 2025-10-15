#include "temperature_utils.hpp"
#include <gtest/gtest.h>


// User Story 1.1: Convert Celsius to Kelvin

// Test freezing point: 0°C should be 273 K
TEST(TemperatureUtils, FreezingPoint_Celsius_ToKelvin)
{
    EXPECT_EQ(CelsiusToKelvin(0), 273);
}
// Test boiling point: 100°C should be 373 K
TEST(TemperatureUtils, BoilingPoint_Celsius_ToKelvin)
{
    EXPECT_EQ(CelsiusToKelvin(100), 373);
}
// Test absolute zero: -273°C should be 0 K
TEST(TemperatureUtils, AbsoluteZero_Celsius_ToKelvin)
{
    EXPECT_EQ(CelsiusToKelvin(-273), 0);
}
// Test typical room temperature: 25°C should be 298 K
TEST(TemperatureUtils, RoomTemp_Celsius_ToKelvin)
{
    EXPECT_EQ(CelsiusToKelvin(25), 298);
}

// User Story 1.2: Convert Celsius Decigrades to Celsius

// Test zero decigrade: 0 decigrade should be 0°C
TEST(TemperatureUtils, ZeroDecigrade_ToCelsius)
{
    EXPECT_EQ(CelsiusDecigradeToCelsius(0), 0);
}
// Test positive decigrade: 100 decigrade should be 10°C
TEST(TemperatureUtils, PositiveDecigrade_ToCelsius)
{
    EXPECT_EQ(CelsiusDecigradeToCelsius(100), 10);
}
// Edge case: negative decigrade: -50 decigrade should be -5°C
TEST(TemperatureUtils, NegativeDecigrade_ToCelsius)
{
    EXPECT_EQ(CelsiusDecigradeToCelsius(-50), -5);
}
// Edge case: non-multiple of 10: 37 decigrade should be 3°C (truncation)
TEST(TemperatureUtils, NonMultipleOf10_ToCelsius)
{
    EXPECT_EQ(CelsiusDecigradeToCelsius(37), 3);
}
// Edge case: very large decigrade value: 10000 decigrade should be 1000°C
TEST(TemperatureUtils, LargeDecigrade_ToCelsius)
{
    EXPECT_EQ(CelsiusDecigradeToCelsius(10000), 1000);
}

// User Story 1.3: Convert Kelvin to Celsius

// Test freezing point: 273 K should be 0°C
TEST(TemperatureUtils, FreezingPoint_Kelvin_ToCelsius)
{
    EXPECT_EQ(KelvinToCelsius(273), 0);
}
// Test boiling point: 373 K should be 100°C
TEST(TemperatureUtils, BoilingPoint_Kelvin_ToCelsius)
{
    EXPECT_EQ(KelvinToCelsius(373), 100);
}
// Test absolute zero: 0 K should be -273°C
TEST(TemperatureUtils, AbsoluteZero_Kelvin_ToCelsius)
{
    EXPECT_EQ(KelvinToCelsius(0), -273);
}
// Test typical room temperature: 298 K should be 25°C
TEST(TemperatureUtils, RoomTemp_Kelvin_ToCelsius)
{
    EXPECT_EQ(KelvinToCelsius(298), 25);
}
// Additional test case
TEST(TemperatureUtils, WhenKelvinToCelsiusIsCalledWith300_Then27ShouldBeReturned)
{
    EXPECT_EQ(KelvinToCelsius(300), 27);
}