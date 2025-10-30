#include "at_codings.hpp"

AtCodings::AtCodings()
    : filter_(),
      raw_temp_facade_(),
      theremal_reader_(filter_, raw_temp_facade_),
      hardware_monitor_(theremal_reader_, codings_), 
      codings_()
{

}
