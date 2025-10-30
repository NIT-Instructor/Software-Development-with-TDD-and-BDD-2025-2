// #include "gtest/gtest.h"
// #include "gmock/gmock.h"

// #include "ut_hardware_monitor.hpp"

// using ::testing::AtLeast;
// using ::testing::Return;
// using ::testing::_;

// TEST_F(UtHardwareMonitor, CheckProvidedCoding_ReportsOverheat_WhenAboveMax)
// {
//     EXPECT_CALL(mock_codings_, AreCodingsPlausable()).WillOnce(Return(true));
//     EXPECT_CALL(mock_codings_, GetMinTreashold()).WillOnce(Return(10));
//     EXPECT_CALL(mock_codings_, GetMaxTreashold()).WillOnce(Return(50));
//     EXPECT_CALL(mock_system_alarm_handler_, ReportOverheatingAlarm()).Times(1);
//     EXPECT_CALL(mock_system_alarm_handler_, ReportUnderheatingAlarm()).Times(0);

//     hardware_monitor_.checkProvidedCoding(75);
// }

// TEST_F(UtHardwareMonitor, CheckProvidedCoding_ReportsUnderheat_WhenAtOrBelowMin)
// {
//     EXPECT_CALL(mock_codings_, AreCodingsPlausable()).WillOnce(Return(true));
//     EXPECT_CALL(mock_codings_, GetMinTreashold()).WillOnce(Return(10));
//     EXPECT_CALL(mock_codings_, GetMaxTreashold()).WillOnce(Return(50));
//     EXPECT_CALL(mock_system_alarm_handler_, ReportUnderheatingAlarm()).Times(1);
//     EXPECT_CALL(mock_system_alarm_handler_, ReportOverheatingAlarm()).Times(0);

//     hardware_monitor_.checkProvidedCoding(5);
// }

// TEST_F(UtHardwareMonitor, CheckProvidedCoding_NoAlarms_WhenCodingsNotPlausible)
// {
//     EXPECT_CALL(mock_codings_, AreCodingsPlausable()).WillOnce(Return(false));
//     // when not plausible, no alarm calls expected
//     EXPECT_CALL(mock_system_alarm_handler_, ReportOverheatingAlarm()).Times(0);
//     EXPECT_CALL(mock_system_alarm_handler_, ReportUnderheatingAlarm()).Times(0);

//     hardware_monitor_.checkProvidedCoding(0);
//     hardware_monitor_.checkProvidedCoding(100);
// }

// TEST_F(UtHardwareMonitor, Start_PeriodicallyReadsTemperature_AndTriggersAlarms)
// {
//     // allow codings to be plausible and return thresholds
//     EXPECT_CALL(mock_codings_, AreCodingsPlausable()).WillRepeatedly(Return(true));
//     EXPECT_CALL(mock_codings_, GetMinTreashold()).WillRepeatedly(Return(10));
//     EXPECT_CALL(mock_codings_, GetMaxTreashold()).WillRepeatedly(Return(50));

//     // thermal reader will produce an overheat value repeatedly
//     EXPECT_CALL(mock_thermal_reader_, UpdateCurrentTemp()).Times(AtLeast(1));
//     EXPECT_CALL(mock_thermal_reader_, ReadFilteredTemperature()).WillRepeatedly(Return(75));

//     // expect at least one overheat report during the run
//     EXPECT_CALL(mock_system_alarm_handler_, ReportOverheatingAlarm()).Times(AtLeast(1));

//     hardware_monitor_.start();
//     std::this_thread::sleep_for(std::chrono::milliseconds(250)); // allow a few periods to run
//     hardware_monitor_.stop();
// }