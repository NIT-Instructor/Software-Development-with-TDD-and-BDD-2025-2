#include "ut_thermal_reader.hpp"

UtThermalReader::UtThermalReader() {}

void UtThermalReader::SetUp()
{
    std::cout << "SetUp" << std::endl;
    temperature_reader_ = new ThermalReader(mock_filter_);
}

void UtThermalReader::TearDown()
{
    std::cout << "TearDown" << std::endl;
    delete temperature_reader_;
}