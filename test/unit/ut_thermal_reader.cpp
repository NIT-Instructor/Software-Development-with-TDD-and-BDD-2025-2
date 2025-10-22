#include "ut_thermal_reader.hpp"

UtThermalReader::UtThermalReader()
{
    // Students need to implement
}

void UtThermalReader::TearDown()
{
    std::cout << "TearDown" << std::endl;
    delete temperatureReader_;
}

void UtThermalReader::SetUp()
{
    std::cout << "SetUp" << std::endl;
    temperatureReader_ = new ThermalReader(mockFilter_);
}
