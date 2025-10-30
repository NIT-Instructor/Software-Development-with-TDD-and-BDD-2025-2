#include "ut_system_alarm_handler.hpp"

// SystemAlarmHandler should provide means to report overheating alarms
TEST_F(UtSystemAlarmHandler, WhenReportOverheatingAlarmIsCalled_ThenLogsOverheatingMessage)
{
    const int overheating_temp = 75;
    
    // When overheating alarm is reported
    system_alarm_handler_.ReportOverheatingAlarm(overheating_temp);
    
    // Then message should be logged to console
    std::string output = captured_output_.str();
    EXPECT_NE(output.find("ALARM"), std::string::npos);
    EXPECT_NE(output.find("Overheating"), std::string::npos);
    EXPECT_NE(output.find("75"), std::string::npos);
}

// SystemAlarmHandler should provide means to report underheating alarms  
TEST_F(UtSystemAlarmHandler, WhenReportUnderheatingAlarmIsCalled_ThenLogsUnderheatingMessage)
{
    const int underheating_temp = -35;
    
    // When underheating alarm is reported
    system_alarm_handler_.ReportUnderheatingAlarm(underheating_temp);
    
    // Then message should be logged to console
    std::string output = captured_output_.str();
    EXPECT_NE(output.find("ALARM"), std::string::npos);
    EXPECT_NE(output.find("Underheating"), std::string::npos);
    EXPECT_NE(output.find("-35"), std::string::npos);
}

// SystemAlarmHandler should log every reported alarm on the console
TEST_F(UtSystemAlarmHandler, WhenMultipleAlarmsAreReported_ThenAllAlarmsAreLogged)
{
    // When multiple alarms are reported
    system_alarm_handler_.ReportOverheatingAlarm(80);
    system_alarm_handler_.ReportUnderheatingAlarm(-40);
    
    // Then both should be logged
    std::string output = captured_output_.str();
    
    // Should contain both alarm messages
    EXPECT_NE(output.find("Overheating"), std::string::npos);
    EXPECT_NE(output.find("Underheating"), std::string::npos);
    EXPECT_NE(output.find("80"), std::string::npos);
    EXPECT_NE(output.find("-40"), std::string::npos);
}

// SystemAlarmHandler should handle different temperature values correctly
TEST_F(UtSystemAlarmHandler, WhenDifferentTemperatureValuesAreReported_ThenCorrectValuesAreLogged)
{
    // Test various temperature values
    std::vector<int> test_temps = {100, 0, -50, 25};
    
    for (int temp : test_temps) {
        captured_output_.str(""); // Clear previous output
        captured_output_.clear();
        
        if (temp > 60) { // Assuming 60 is typical max threshold
            system_alarm_handler_.ReportOverheatingAlarm(temp);
        } else {
            system_alarm_handler_.ReportUnderheatingAlarm(temp);
        }
        
        std::string output = captured_output_.str();
        EXPECT_NE(output.find(std::to_string(temp)), std::string::npos);
    }
}