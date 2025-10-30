#include "gtest/gtest.h"
#include "ut_codings.hpp"

TEST_F(UtCodings, DefaultThresholdsAreCorrect)
{
    EXPECT_EQ(codings_.GetMinThreshold(), 10);
    EXPECT_EQ(codings_.GetMaxThreshold(), 500);
}

TEST_F(UtCodings, CanUpdateThresholdValues)
{
    codings_.SetMinThreshold(20);
    codings_.SetMaxThreshold(400);

    EXPECT_EQ(codings_.GetMinThreshold(), 20);
    EXPECT_EQ(codings_.GetMaxThreshold(), 400);
}

TEST_F(UtCodings, ValidThresholdRangePassesCheck)
{
    codings_.SetMinThreshold(11);
    codings_.SetMaxThreshold(499);
    EXPECT_TRUE(codings_.CheckThresholds(600));
}
