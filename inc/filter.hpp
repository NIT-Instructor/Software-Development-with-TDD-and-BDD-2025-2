#pragma once

#include <array>
#include <cstdint>

#include "common.hpp"

constexpr std::size_t BufferSize = 9;

class Filter
{
  public:
    Filter();
  PRIVATE:
    std::array<uint8_t, BufferSize> buffer_;
};
