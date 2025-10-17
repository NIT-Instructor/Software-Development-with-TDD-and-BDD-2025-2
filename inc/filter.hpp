#pragma once

#include <array>
#include <cstdint>
#include "common.hpp"

constexpr uint8_t kBufferSize = 9;

class Filter
{
  public:
    Filter();
    void FillBufferWithValue(float value);
    float FilterData();

  PRIVATE:
    std::array<float, kBufferSize> buffer_;
};