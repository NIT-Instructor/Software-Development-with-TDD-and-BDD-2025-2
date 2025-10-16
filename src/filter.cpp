

// Filter class constructor and FilterData method to be implemented by students
#pragma once
 
#include "filter.hpp"
#include <array>
#include <cstdint>
#include <cstddef>
#include "common.hpp"
 

   Filter::Filter () {
    for (int i = 0; i <= kBufferSize; i++) {
        buffer_[i] = 1;
    }
   }
   uint8_t Filter::FilterData() {
     return 1;
   }

