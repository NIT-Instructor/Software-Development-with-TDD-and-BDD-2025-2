#pragma once

#include <array>
#include <cstdint>

#include "common.hpp"

#ifdef TESTING
#define PRIVATE public
#else
#define PRIVATE private
#endif

constexpr uint8_t kBufferSize = 9;

class Filter
{
  public:
    Filter();
    int FilterData();
  PRIVATE:
  std::array<int, kBufferSize> buffer_;
};
