#include "at_hardware_monitor.hpp"

struct HardwareMonitorConditions {
    /*
     * heating_status:
            0 -> Normal
     *      1 -> Underheating
     *      2 -> Overheating
     *      3 -> Not Plausible
     */
    int num_of_checks;
    std::vector<int> heating_status;
};

static const HardwareMonitorConditions kHardwareMonitorConditions[] = {{3, {1, 1, 1}}};

class FixtureHardwareMonitor : public AtHardwareMonitor, public ::testing::WithParamInterface<HardwareMonitorConditions> {};

INSTANTIATE_TEST_SUITE_P(HardwareMonitorSuite, FixtureHardwareMonitor, ::testing::ValuesIn(kHardwareMonitorConditions));

TEST_P(FixtureHardwareMonitor, GivenValues)
{
    codings.SetMaxThreshold(14);
    codings.SetMinThreshold(5);

    for (int i = 0; i < GetParam().num_of_checks; ++i)
    {
        EXPECT_EQ(hardware_monitor.hwm_function(), GetParam().heating_status[i]);
    }

    raw_temp_facade.restartTemp();
}