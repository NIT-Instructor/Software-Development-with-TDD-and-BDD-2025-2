#include "at_thermal_reader.hpp"
#include "at_hardware_monitor.hpp"
#include "at_codings.hpp"


struct CodingsConditions
{
    int minThreshold;
    int maxThreshold;
};


static const CodingsConditions kCodingsConditions[] = {
    {10, 500},
    {100, 700},
    {5, 10},
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
        codings_.SetMinThreshold(param.minThreshold);
        float result = codings_.GetMinThreshold();
       
        EXPECT_EQ(param.minThreshold, result);

};

TEST_P(FixtureClassCodings, CheckMaxThreshold)
    {
        const auto &param = GetParam();
        codings_.SetMaxThreshold(param.maxThreshold);
        float max = codings_.GetMaxThreshold();

        EXPECT_EQ(max, param.maxThreshold);

};


TEST_P(FixtureClassCodings, CheckThresholdBehaviour)
{
    codings_.SetMinThreshold(GetParam().minThreshold);
    codings_.SetMaxThreshold(GetParam().maxThreshold);

    int result = hardware_monitor_.Update();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (result < GetParam().minThreshold) {
        EXPECT_TRUE(codings_.CheckThresholds(result));
    } else if (result > GetParam().maxThreshold)
    {
        EXPECT_TRUE(codings_.CheckThresholds(result));
    } else {
        EXPECT_FALSE(codings_.CheckThresholds(result));
    }
}


