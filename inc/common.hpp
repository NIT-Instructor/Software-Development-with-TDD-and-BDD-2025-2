#pragma once

// PRIVATE macro for accessing private members during testing
#ifdef TESTING
    #define PRIVATE public
#else
    #define PRIVATE private
#endif

// MOCKABLE macro - students need to define this for Exercise 3
#ifdef MOCK_ENABLE
#define MOCKABLE virtual
#else
#define MOCKABLE
#endif