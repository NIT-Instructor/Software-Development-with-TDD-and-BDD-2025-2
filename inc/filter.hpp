#pragma once
 
#include <array>
#include <cstdint>
#include <cstddef>
#include "common.hpp"
 
constexpr uint8_t kBufferSize = 9;
 
class Filter
{
  public:
    Filter();

 
  PRIVATE:
    std::array<uint8_t, kBufferSize> buffer_;
    uint8_t FilterData();
    void UpdateFilterData(uint8_t new_value);
};