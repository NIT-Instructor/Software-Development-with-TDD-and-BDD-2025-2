#include "temperature_utils.hpp"

int KELVIN_FACTOR = 273;

// Function definitions
int CelsiusToKelvin(int celsius_)
{
    return celsius_ + KELVIN_FACTOR;
}

int CelsiusDecigradeToCelsius(int decigrade_)
{
    return decigrade_ / 10;
}

int KelvinToCelsius(int kelvin_)
{
    return kelvin_ - KELVIN_FACTOR;
}