#pragma once

#ifdef TESTING
  #define PRIVATE public
    #ifndef MOCK_ENABLE
      #error "MOCK_ENABLE must be defined when building with TESTING"
    #endif
#else
  #define PRIVATE private
#endif

#ifdef MOCK_ENABLE
  #define MOCKABLE virtual
#else
  #define MOCKABLE
#endif