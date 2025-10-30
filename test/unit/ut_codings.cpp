
#include "ut_codings.hpp"

UtCodings::UtCodings() : mock_filter_(), mock_raw_temp_facade_(), mock_temperature_reader_(mock_filter_, mock_raw_temp_facade_), hardware_monitor_(mock_temperature_reader_, codings_), codings_()
{};