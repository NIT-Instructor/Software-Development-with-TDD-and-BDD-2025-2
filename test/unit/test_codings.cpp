#include "ut_codings.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

TEST_F(UtCodings, WhenGetMaxThresholdIsCalled_ThenMaxThresholdShouldBeReturned)
{
    const int maxThreshold = 77;
    codings_.SetMaxThreshold(maxThreshold);
    ASSERT_EQ(codings_.GetMaxThreshold(), maxThreshold);
}

TEST_F(UtCodings, WhenGetMinThresholdIsCalled_ThenMinTresholdShouldBeReturned)
{
    const int minThreshold = -6;
    codings_.SetMinThreshold(minThreshold);
    ASSERT_EQ(codings_.GetMinThreshold(), minThreshold);
}

TEST_F(UtCodings, WhenAreCodingsPlausibleIsCalled_ThenTrueShouldBeReturned)
{
    const int maxThreshold = 23;
    const int minThreshold = 4;
    codings_.SetMaxThreshold(maxThreshold);
    codings_.SetMinThreshold(minThreshold);
    ASSERT_TRUE(codings_.AreCodingsPlausible());
}