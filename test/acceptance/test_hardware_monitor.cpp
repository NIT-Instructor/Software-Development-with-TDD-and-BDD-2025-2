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
