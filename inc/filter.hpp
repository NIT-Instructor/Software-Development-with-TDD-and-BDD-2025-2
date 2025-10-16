#pragma once

#include <array>
#include <cstdint>
#include "common.hpp"

constexpr uint8_t kBufferSize = 9;

class Filter
{
  public:
    Filter();
    void FillBufferWithWalue(uint8_t value);
    float FilterData();

  PRIVATE:
    std::array<uint8_t, kBufferSize> buffer_;
};