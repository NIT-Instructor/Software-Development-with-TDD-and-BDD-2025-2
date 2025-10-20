#pragma once

#include <array>
#include <cstdint>

#include "common.hpp"

constexpr std::size_t kBufferSize = 9;

class Filter
{
  public:
    Filter();
    int FilterData() const;
  PRIVATE:
  std::array<int, kBufferSize> buffer_;
};
