#include <gtest/gtest.h>
#include "codings.hpp"

struct PlausibilityTest
{
    int min;
    int max;
    bool expected;
};

class UtCodingsPlausibility : public ::testing::TestWithParam<PlausibilityTest> {};

TEST_P(UtCodingsPlausibility, ChecksOrderingAndLimits)
{
    const auto& p = GetParam();
    Codings c;

    c.SetMaxThreshold(p.max);
    c.SetMinThreshold(p.min);

    EXPECT_EQ(c.AreCodingsPlausable(), p.expected);
}

TEST(CodingsPlausibility, CodingsShouldProvideMinimumAndMaximumThreshold)
{
    Codings c;
    c.SetMinThreshold(0);
    c.SetMaxThreshold(50);

    EXPECT_EQ(c.GetMaxThreshold(), 50);
    EXPECT_EQ(c.GetMinThreshold(), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Plausibility,
    UtCodingsPlausibility,
    ::testing::Values(
        PlausibilityTest{0, 45, true},
        PlausibilityTest{-5, 5, true},
        PlausibilityTest{20, 20, false},
        PlausibilityTest{30, 10, false},
        PlausibilityTest{30, 10, false}
    )
);