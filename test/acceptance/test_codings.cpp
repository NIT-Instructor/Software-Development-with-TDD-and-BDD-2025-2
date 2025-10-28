#include "at_codings.hpp"

struct CodingsConditions
{
    int min_threshold;
    int max_threshold;
    bool plausable;
};

std::ostream& operator<<(std::ostream& os, const CodingsConditions& c)
{
    os << "{min_threshold: " << c.min_threshold
       << ", max_threshold: " << c.max_threshold
       << ", plausable: " << std::boolalpha << c.plausable
       << "}";
    return os;
}

static const CodingsConditions kCodingsConditions[] = {
    {-21, 60, false},
    {18, 101, false},
    {-15, 23, true},
    {1, 666, false}
};

class FixtureCodings : public AtCodings, public ::testing::WithParamInterface<CodingsConditions>
{
};

INSTANTIATE_TEST_SUITE_P(CodingsSuite, FixtureCodings, ::testing::ValuesIn(kCodingsConditions));

TEST_P(FixtureCodings, CodingsTest)
{
    codings_.SetMaxThreshold(GetParam().max_threshold);
    codings_.SetMinThreshold(GetParam().min_threshold);

    ASSERT_EQ(codings_.GetMaxThreshold(), GetParam().max_threshold);
    ASSERT_EQ(codings_.GetMinThreshold(), GetParam().min_threshold);

    ASSERT_EQ(codings_.AreCodingsPlausable(), GetParam().plausable);
}