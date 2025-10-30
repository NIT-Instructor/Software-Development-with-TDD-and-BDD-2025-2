#include "at_thermal_reader.hpp"
#include "at_hardware_monitor.hpp"
#include "at_codings.hpp"

struct CodingsConditions
{
    int minTreshold;
    int maxTreshold;
};
static const CodingsConditions kCodingsConditions[] = {
    {10, 500}
};

class FixtureClassCodings : public AtCodings,
                                    public ::testing::WithParamInterface<CodingsConditions>
{
};

INSTANTIATE_TEST_SUITE_P(CodingsSuite,
                        FixtureClassCodings,
                        ::testing::ValuesIn(kCodingsConditions));


TEST_P(FixtureClassCodings, CheckMinThreshold)
{
        const auto &param = GetParam();
        codings_.SetMinThreshold(10);
        float result = codings_.GetMinThreshold();
       
        EXPECT_EQ(param.minTreshold, result);

};

TEST_P(FixtureClassCodings, CheckMaxThreshold)
    {
        const auto &param = GetParam();

        float max = codings_.GetMaxThreshold();

        EXPECT_EQ(max, param.maxTreshold);

};
