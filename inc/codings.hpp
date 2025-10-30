#pragma once

#include "common.hpp"

constexpr int kDefaultMinThreshold = -30;
constexpr int kDefaultMaxThreshold = 60;

class Codings
{
  public:
    Codings();
    virtual ~Codings() = default;

    MOCKABLE int GetMinThreshold() const;
    MOCKABLE int GetMaxThreshold() const;
    MOCKABLE bool AreCodingsPlausable() const;
    void SetMaxThreshold(int max);
    void SetMinThreshold(int min);
  
  private:
    int min_threshold;
    int max_threshold;
};