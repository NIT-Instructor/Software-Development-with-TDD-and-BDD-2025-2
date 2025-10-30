#include "at_hardware_monitor.hpp"
#include <thread>

using namespace std::chrono_literals;

struct PeriodParams {
    int periods;
    int expected_filtered_value;
};

class HardwareMonitorPeriodParamTest
    : public AtHardwareMonitor,                      // base fixture setup/teardown
      public ::testing::WithParamInterface<PeriodParams> // adds parameters
{
};

TEST_P(HardwareMonitorPeriodParamTest, UpdatesTemperatureEvery100ms)
{
    const auto p = GetParam();
    hardware_monitor_->StartMonitoring();

    auto total = std::chrono::milliseconds(100 * p.periods);
    std::this_thread::sleep_for(total);

    hardware_monitor_->StopMonitoring();
    auto filtered_value = thermal_reader_->ReadFilteredTemperature();
    EXPECT_NEAR(filtered_value, p.expected_filtered_value, 3);
    raw_temp_facade_->ResetSensor();
}

// Instantiate test cases
INSTANTIATE_TEST_SUITE_P(
    Periodic,
    HardwareMonitorPeriodParamTest,
    ::testing::Values(
        PeriodParams{2, 0},
        PeriodParams{4, 1}
    )
);