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

  private:
  PRIVATE:
    std::array<uint8_t, kBufferSize> buffer_;

};
