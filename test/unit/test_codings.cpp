#include "ut_codings.hpp"

TEST_F(UtCodings, AreCodingsPlausable_ReturnsTrue_WhenValueWithinThreshold)
{
    int test_value = 50;
    bool result = codings_.AreCodingsPlausable(test_value);
    EXPECT_TRUE(result);
}

TEST_F(UtCodings, UtCodings_GetMaxTreashold_Test)
{
    int max_treashold = codings_.GetMaxTreashold();
    EXPECT_EQ(max_treashold, 100);
}

TEST_F(UtCodings, UtCodings_GetMinTreashold_Test)
{
    int min_treashold = codings_.GetMinTreashold();
    EXPECT_EQ(min_treashold, 0);
}