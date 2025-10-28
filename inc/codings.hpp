#pragma once

#include "common.hpp"

#define MINIMUM_THRESHOLD = -20
#define MAXIMUM_THRESHOLD = 60

class Codings {
  public:
    Codings();

    MOCKABLE int GetMinThreshold();
    MOCKABLE int GetMaxThreshold();
    MOCKABLE bool AreCodingsPlausable();

    void SetMaxThreshold(int value);
    void SetMinThreshold(int value);

  PRIVATE:
    int min_threshold_;
    int max_threshold_;

};