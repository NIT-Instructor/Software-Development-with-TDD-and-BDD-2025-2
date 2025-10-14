#include "temperature_utils.hpp"
#include <gtest/gtest.h>

// User Story 1.1: Convert Celsius to Kelvin
TEST(TemperatureUtils, WhenCelsiusToKelvinIsCalledWith0_Then273ShouldBeReturned)
{
    EXPECT_EQ(CelsiusToKelvin(0), 273);
}

TEST(TemperatureUtils, WhenCelsiusDecigradesToCelsiusIsCalledWith100_Then10ShouldBeReturned)
{
    EXPECT_EQ(CelsiusDecigradeToCelsius(100), 10);
}

TEST(TemperatureUtils, WhenKelvinToCelsiusIsCalledWith273_Then0ShouldBeReturned)
{
    EXPECT_EQ(KelvinToCelsius(273), 0);
}

TEST(TemperatureUtils, WhenKelvinToCelsiusIsCalledWith300_Then27ShouldBeReturned)
{
    EXPECT_EQ(KelvinToCelsius(300), 27);
}