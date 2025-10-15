#include "temperature_utils.hpp"
#include <gtest/gtest.h>

// User Story 1.1: Convert Celsius to Kelvin
TEST(TemperatureUtils, WhenCelsiusToKelvinIsCalledWith0_Then273ShouldBeReturned)
{
    EXPECT_EQ(CelsiusToKelvin(0), 273);
}

// User Story 1.2: Convert Celsius Decigrades to Celsius
TEST(TemperatureUtils, WhenCelsiusDecigradeToCelsiusIsCalledWith0_Then0ShouldBeReturned)
{
    EXPECT_EQ(CelsiusDecigradeToCelsius(0), 0);
}

// User Story 1.3:Convert Kelvin to Celsius
TEST(TemperatureUtils, WhenKelvinToCelsiusIsCalledWith273_Then0ShouldBeReturned)
{
    EXPECT_EQ(KelvinToCelsius(273), 0);
}