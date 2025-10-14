#include "temperature_utils.hpp"

// Function definitions

int CelsiusToKelvin(int celsius_)
{
    return celsius_ + 273;
}

int CelsiusDecigradeToCelsius(int decigrade_)
{
    return decigrade_ / 10;
}

int KelvinToCelsius(int kelvin_)
{
    return kelvin_ - 273;
}
