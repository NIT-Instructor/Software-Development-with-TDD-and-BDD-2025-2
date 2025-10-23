#include "at_thermal_reader.hpp"

struct ThermalRaderConditions
{
    int num_of_update_currect_temp_called;
    int expected_filterd_value;
};

static const ThermalRaderConditions kThtermalReadeContitions[] = {{2, 0}, {3, 1}};

class FixtureClassThermalReader : public AtThermalReader, public ::testing::WithParamInterface<ThermalRaderConditions>
{
};
// Fixture class must be derived from testing::Test and testing::WithParamInterface<T>
//                                 or testing::TestWithParam<T>, which itself is derived from this two classes
// Because AtLumClientCore inherent testing::Test
// Fixture class derives from WithParamInterface only.

INSTANTIATE_TEST_SUITE_P(ThermalRaderSuite, FixtureClassThermalReader, ::testing::ValuesIn(kThtermalReadeContitions));

TEST_P(FixtureClassThermalReader, Given)
{
    for (int i = 0; i < GetParam().num_of_update_currect_temp_called; ++i)
    {
        theremal_reader_.UpdateCurrentTemp();
    }
    auto filtered_temp = theremal_reader_.ReadFilteredTemperature();
    EXPECT_EQ(filtered_temp, GetParam().expected_filterd_value);
}
