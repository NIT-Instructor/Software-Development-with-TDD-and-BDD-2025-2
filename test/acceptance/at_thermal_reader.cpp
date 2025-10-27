#include "at_thermal_reader.hpp"

AtThermalReader::AtThermalReader() : filter_(), raw_temp_facade_(), theremal_reader_(filter_, raw_temp_facade_)
{
}