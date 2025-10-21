#pragma once

#include <array>
#include <cstdint>

#include "common.hpp"

constexpr std::size_t kBufferSize = 9;

class Filter
{
  public:
    Filter();
    virtual ~Filter();

    bool UpdateFilterData(int new_value);
    MOCKABLE int FilterData() const;

    PRIVATE : std::array<uint8_t, kBufferSize> buffer_;
    int                                        head_;
};
