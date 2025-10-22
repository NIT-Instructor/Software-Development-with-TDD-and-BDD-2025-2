#include "at_thermal_reader.hpp"

AtThermalReader::AtThermalReader() : theremal_reader_(filter_, raw_temp_facade_)
{
}