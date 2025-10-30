#include "codings.hpp"
#include <gtest/gtest.h>

TEST(CodingsLocalInstances, AreCodingsPlausable_ForCustomRanges)
{
    Codings c1(5, 60);
    EXPECT_TRUE(c1.AreCodingsPlausable());
    EXPECT_EQ(c1.GetMinTreashold(), 5);
    EXPECT_EQ(c1.GetMaxTreashold(), 60);

    Codings c2(0, 120);
    EXPECT_TRUE(c2.AreCodingsPlausable());

    Codings c3(0, 130);
    EXPECT_FALSE(c3.AreCodingsPlausable());

    Codings invalid(50, 10);
    EXPECT_FALSE(invalid.AreCodingsPlausable());
}