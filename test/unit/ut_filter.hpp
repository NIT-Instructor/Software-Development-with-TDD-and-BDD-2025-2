#pragma once

#include "filter.hpp"
#include <gtest/gtest.h>

class UtFilter : public ::testing::Test
{
public:
  UtFilter();
  void SetUp() override;

protected:
  Filter filter_;
};
