#include "temperature_utils.hpp"
#include <gtest/gtest.h>

// User Story 1.1: Convert Celsius to Kelvin
TEST(TemperatureUtils, WhenCelsiusToKelvinIsCalledWith0_Then273ShouldBeReturned)
{
    EXPECT_EQ(CelsiusToKelvin(0), 273);
}
// Students will add more test cases for other temperature conversions