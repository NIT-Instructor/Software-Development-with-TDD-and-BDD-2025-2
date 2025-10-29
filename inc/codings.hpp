#pragma once

#include "common.hpp"


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

    static constexpr int MINIMUM_THRESHOLD = -20;
    static constexpr int MAXIMUM_THRESHOLD = 60;

};