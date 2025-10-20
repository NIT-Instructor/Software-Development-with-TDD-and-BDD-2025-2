#pragma once

// PRIVATE macro for accessing private members during testing
#ifdef TESTING
    #define PRIVATE public
#else
    #define PRIVATE private
#endif

// MOCKABLE macro - students need to define this for Exercise 3
