#include "temperature_utils.hpp"

int KELVIN_FACTOR = 273;

// Function definitions
int CelsiusToKelvin(int celsius_)
{
    // Celsius + 273
    return celsius_ + KELVIN_FACTOR;
}

int CelsiusDecigradeToCelsius(int decigrade_)
{
    // Decigrade / 10
    return decigrade_ / 10;
}

int KelvinToCelsius(int kelvin_)
{
    // Kelvin - 273
    return kelvin_ - KELVIN_FACTOR;
}