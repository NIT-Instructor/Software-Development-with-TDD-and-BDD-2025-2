#pragma once

#include <array>
#include <cstdint>

#include "common.hpp"

constexpr uint8_t kBufferSize = 9;

class Filter
{
  public:
    Filter();
    int FilterData();
  PRIVATE:
  std::array<int, kBufferSize> buffer_;
};
