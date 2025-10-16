#include "temperature_utils.hpp"

int CelsiusToKelvin(int celsius_)
{
    return celsius_ + 273;
}

int CelsiusDecigradeToCelsius(int decigrade_)
{
    return decigrade_ / 10;
}
