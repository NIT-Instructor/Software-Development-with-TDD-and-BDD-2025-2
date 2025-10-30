#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "codings.hpp"

class UtCodings : public ::testing::Test {
public:
  UtCodings();

protected:
  Codings codings_;
};