#pragma once

#include "codings.hpp"
#include <gtest/gtest.h>

class AtCodings : public testing::Test {
  public:
    AtCodings();

  protected:
    Codings codings_;

};