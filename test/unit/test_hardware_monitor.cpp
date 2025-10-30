#include "gtest/gtest.h"
#include "ut_thermal_reader.hpp"
#include "ut_hardware_monitor.hpp"
//Project -Harware Monitor, Scenario 1

TEST_F(UtHardwareMonitor, WhenUpdateIsCalled_ThenThermalReaderUpdateCurrentTempIsCalled)
{
    EXPECT_CALL(mock_temperature_reader_, UpdateCurrentTemp()).WillOnce(testing::Return(true));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    hardware_monitor_.Update();

}
// //Project -Harware Monitor, Scenario 1: Verify that Update() calls ThermalReader::UpdateCurrentTemp() approximately every 100ms
TEST_F(UtHardwareMonitor, WhenUpdateCalledPeriodically_ThenUpdateCurrentTempOccursWithinTimingTolerance)
{
    using namespace std::chrono;

    const int kToleranceMs = 30;
    const int kIntervalMs  = 100;
    const int kNumCycles   = 5;

    EXPECT_CALL(mock_temperature_reader_, UpdateCurrentTemp())
        .Times(kNumCycles)
        .WillRepeatedly(testing::Return(true));

    auto start = steady_clock::now();

    for (int i = 0; i <= kNumCycles; ++i)
    {
        hardware_monitor_.Update();
        std::this_thread::sleep_for(milliseconds(kIntervalMs));
    }

    auto end = steady_clock::now();
    auto elapsed_ms = duration_cast<milliseconds>(end - start).count();

    int expected_total = kNumCycles * kIntervalMs;
    EXPECT_NEAR(elapsed_ms, expected_total, kToleranceMs * kNumCycles)
        << "Periodic updates should respect ~100ms timing tolerance per cycle.";
}