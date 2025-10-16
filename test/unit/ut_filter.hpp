#pragma once

#include "filter.hpp"
#include <gtest/gtest.h>

class UtFilter : public ::testing::Test
{
public:
  UtFilter();
  void SetUp() override;
  void InitializeBuffer(uint8_t i);

protected:
  Filter filter_;
};
