#include "temperature_utils.hpp"

// Function definitions
int FACTOR = 273;
int CelsiusToKelvin(int celsius_)
{
    // Example function definition (TODO: students will implement this)
   // return 273; // Placeholder
    //return 0;
    return celsius_ + FACTOR;
}

int CelsiusDecigradeToCelsius(int decigrade_)
{
    // Example function definition (TODO: students will implement this)
    //return 0; // Placeholder
    //return 10;
    return decigrade_ / 10;
}

int KelvinToCelsius(int kelvin_) 
{
    return kelvin_ - FACTOR;
}