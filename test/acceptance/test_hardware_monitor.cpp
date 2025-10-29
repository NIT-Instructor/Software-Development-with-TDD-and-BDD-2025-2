#include "at_hardware_monitor.hpp"


static const int kNumOfUpdates = 3;
static const int new_temperature_data[kNumOfUpdates] = {0, 1, 2};

class FixtureClassHardwareMonitor : public AtHardwareMonitor, public ::testing::WithParamInterface<int>
{
};

INSTANTIATE_TEST_SUITE_P(HardwareMonitorSuite, FixtureClassHardwareMonitor, ::testing::ValuesIn(new_temperature_data));

TEST_P(FixtureClassHardwareMonitor, Given)
{
    for (int i = 0; i < kNumOfUpdates; ++i)
    {
        hardware_monitor_.updateFilterTemperatures(GetParam());
    }

    int result = hardware_monitor_.readFilteredTemperatures();
    EXPECT_EQ(result, 0);
}