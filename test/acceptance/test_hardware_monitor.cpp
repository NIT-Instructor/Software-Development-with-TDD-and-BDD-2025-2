#include "at_thermal_reader.hpp"
#include "at_hardware_monitor.hpp"

struct HardwareMonitorConditions
{
    int num_of_update_current_temp_called;
    int expected_filter_updates;

};
static const HardwareMonitorConditions kHardwareMonitorConditions[] = {
    {1, 1}
};
class FixtureClassHardwareMonitor : public AtHardwareMonitor,
                                    public ::testing::WithParamInterface<HardwareMonitorConditions>
{
};


INSTANTIATE_TEST_SUITE_P(HardwareMonitorSuite,
                        FixtureClassHardwareMonitor,
                        ::testing::ValuesIn(kHardwareMonitorConditions));

// Project - User Story1 - Scenario 1
TEST_P(FixtureClassHardwareMonitor, WhenRunningPeriodicUpdate_ThenThermalReaderIsUpdatedEvery100ms)
    {
        const auto &param = GetParam();
        int actual_updates = 0;


        for (int i = 0; i < param.num_of_update_current_temp_called; ++i)
        {
            hardware_monitor_.Update();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            actual_updates++;
        }
        EXPECT_EQ(actual_updates, param.expected_filter_updates);

};

// Project - User Story1 - Scenario 2

TEST_P(FixtureClassHardwareMonitor, WhenUpdatesCalledFasterThan100ms_ThenFilterIsNotUpdatedTooOften)
{
    const auto &param = GetParam();
    int actual_updates = 0;

    for (int i = 0; i < param.num_of_update_current_temp_called; ++i)
    {
        hardware_monitor_.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        actual_updates++;
    }

    EXPECT_LE(actual_updates, param.num_of_update_current_temp_called);
}

// Project - User Story1 - Scenario 3
TEST_P(FixtureClassHardwareMonitor, WhenUpdatesCalledSlowerThan100ms_ThenFilterIsUpdatedEveryCall)
{
    const auto &param = GetParam();
    int actual_updates = 0;

    for (int i = 0; i < param.num_of_update_current_temp_called; ++i)
    {
        hardware_monitor_.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        actual_updates++;
    }

    EXPECT_EQ(actual_updates, param.num_of_update_current_temp_called);
}
// Project - User Story1 - Scenario 4
TEST_P(FixtureClassHardwareMonitor, WhenNoUpdateCalled_ThenFilterRemainsUnchanged)
{
    const auto &param = GetParam();
    int actual_updates = 0;

    EXPECT_EQ(actual_updates, 0);
}

