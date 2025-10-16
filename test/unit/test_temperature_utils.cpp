#include "temperature_utils.hpp"
#include <gtest/gtest.h>

// User Story 1.1: Convert Celsius to Kelvin
TEST(TemperatureUtils, WhenCelsiusToKelvinIsCalledWith0_Then273ShouldBeReturned)
{
    ASSERT_EQ(CelsiusToKelvin(0), 273);
}

// User Story 1.1: Convert Celsius to Kelvin
TEST(TemperatureUtils, WhenCelsiusToKelvinIsCalledWith25_Then298ShouldBeReturned)
{
    ASSERT_EQ(CelsiusToKelvin(25), 298);
}

// User Story 1.2: Convert Celsius Decigrades to Celsius
TEST(TemperatureUtils, WhenCelisusDecigradeToCelisusIsCalledWith100_Then10ShouldBeReturned)
{
    ASSERT_EQ(CelsiusDecigradeToCelsius(100), 10);
}

// User Story 1.2: Convert Celsius Decigrades to Celsius
TEST(TemperatureUtils, WhenCelisusDecigradeToCelisusIsCalledWith0_Then0ShouldBeReturned)
{
    ASSERT_EQ(CelsiusDecigradeToCelsius(0), 0);
}
