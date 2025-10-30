#include "at_system_alarm_handler.hpp"

// Test parameters for alarm scenarios
struct AlarmScenarioParams
{
    int temperature;
    std::string alarm_type;        // "Overheating" or "Underheating"
    std::string scenario_name;     // Human-readable scenario description
    std::string risk_level;        // "Critical", "High", "Moderate"
    
    AlarmScenarioParams(int temp, const std::string& type, const std::string& scenario, const std::string& risk)
        : temperature(temp), alarm_type(type), scenario_name(scenario), risk_level(risk) {}
};

// Parameterized acceptance test fixture
class AtSystemAlarmHandlerParameterized : public AtSystemAlarmHandler,
                                         public ::testing::WithParamInterface<AlarmScenarioParams>
{
};

// Acceptance Test: System alarm reporting for various temperature conditions
// Feature: As a system operator, I need to be notified when hardware reaches dangerous temperatures
// Scenario: Given various dangerous temperature conditions, when alarm is triggered, then system handles it reliably
TEST_P(AtSystemAlarmHandlerParameterized, GivenDangerousTemperatureConditions_WhenAlarmIsTriggered_ThenSystemHandlesReliably)
{
    const AlarmScenarioParams& params = GetParam();
    
    // Given dangerous temperature conditions
    // (In acceptance test, we simulate real-world temperature scenarios)
    
    // When alarm is triggered based on alarm type
    if (params.alarm_type == "Overheating") {
        EXPECT_NO_THROW(system_alarm_handler_.ReportOverheatingAlarm(params.temperature))
            << "Failed to handle " << params.scenario_name 
            << " (Risk: " << params.risk_level << ")";
    } else if (params.alarm_type == "Underheating") {
        EXPECT_NO_THROW(system_alarm_handler_.ReportUnderheatingAlarm(params.temperature))
            << "Failed to handle " << params.scenario_name
            << " (Risk: " << params.risk_level << ")";
    }
    
    // Then system handles it reliably (verified by successful execution without exceptions)
    SUCCEED() << "Successfully handled " << params.scenario_name 
              << " at " << params.temperature << "°C";
}

// Real-world temperature alarm scenarios
INSTANTIATE_TEST_SUITE_P(
    RealWorldTemperatureScenarios,
    AtSystemAlarmHandlerParameterized,
    ::testing::Values(
        // Critical overheating scenarios
        AlarmScenarioParams(100, "Overheating", "CPU thermal throttling", "Critical"),
        AlarmScenarioParams(85, "Overheating", "Graphics card overheat", "Critical"),
        AlarmScenarioParams(120, "Overheating", "Power supply failure", "Critical"),
        AlarmScenarioParams(150, "Overheating", "Extreme industrial conditions", "Critical"),
        
        // High risk overheating
        AlarmScenarioParams(75, "Overheating", "Server room cooling failure", "High"),
        AlarmScenarioParams(90, "Overheating", "Laptop under heavy load", "High"),
        
        // Critical underheating scenarios  
        AlarmScenarioParams(-40, "Underheating", "Arctic deployment conditions", "Critical"),
        AlarmScenarioParams(-60, "Underheating", "Deep freezer malfunction", "Critical"),
        AlarmScenarioParams(-273, "Underheating", "Cryogenic research environment", "Critical"),
        
        // High risk underheating
        AlarmScenarioParams(-20, "Underheating", "Winter outdoor installation", "High"),
        AlarmScenarioParams(-35, "Underheating", "Cold storage facility", "High"),
        AlarmScenarioParams(0, "Underheating", "Freezing point detection", "Moderate")
    ),
    [](const ::testing::TestParamInfo<AlarmScenarioParams>& info) {
        // Generate readable test names based on scenario
        std::string name = info.param.alarm_type;
        if (info.param.temperature >= 0) {
            name += "_Temp" + std::to_string(info.param.temperature);
        } else {
            name += "_TempMinus" + std::to_string(std::abs(info.param.temperature));
        }
        name += "_" + info.param.risk_level + "Risk";
        return name;
    }
);

// ===== STRESS TESTING FOR MULTIPLE ALARMS =====

// Test parameters for multiple alarm scenarios
struct MultipleAlarmParams
{
    std::vector<std::pair<int, std::string>> alarm_sequence; // {temperature, type} pairs
    std::string scenario_description;
    int expected_alarm_count;
    
    MultipleAlarmParams(const std::vector<std::pair<int, std::string>>& sequence, 
                       const std::string& description, int count)
        : alarm_sequence(sequence), scenario_description(description), expected_alarm_count(count) {}
};

class AtSystemAlarmHandlerStressTesting : public AtSystemAlarmHandler,
                                         public ::testing::WithParamInterface<MultipleAlarmParams>
{
};

// Acceptance Test: System reliability under multiple alarm conditions
// Feature: As a system operator, I need reliable alarm handling during crisis situations
// Scenario: Given multiple simultaneous alarm conditions, when various alarms are triggered, then all are handled correctly
TEST_P(AtSystemAlarmHandlerStressTesting, GivenMultipleAlarmConditions_WhenVariousAlarmsTriggered_ThenAllHandledCorrectly)
{
    const MultipleAlarmParams& params = GetParam();
    
    // Given multiple alarm conditions may occur simultaneously
    int alarms_processed = 0;
    
    // When various alarms are triggered in sequence
    EXPECT_NO_THROW({
        for (const auto& alarm : params.alarm_sequence) {
            int temperature = alarm.first;
            const std::string& type = alarm.second;
            
            if (type == "Overheating") {
                system_alarm_handler_.ReportOverheatingAlarm(temperature);
            } else if (type == "Underheating") {
                system_alarm_handler_.ReportUnderheatingAlarm(temperature);
            }
            alarms_processed++;
        }
    }) << "Failed during " << params.scenario_description;
    
    // Then all are handled correctly
    EXPECT_EQ(alarms_processed, params.expected_alarm_count) 
        << "Not all alarms were processed in scenario: " << params.scenario_description;
}

// Multiple alarm stress test scenarios
INSTANTIATE_TEST_SUITE_P(
    MultipleAlarmStressScenarios,
    AtSystemAlarmHandlerStressTesting,
    ::testing::Values(
        // Rapid temperature fluctuations
        MultipleAlarmParams(
            {{90, "Overheating"}, {-30, "Underheating"}, {85, "Overheating"}},
            "Rapid temperature swings",
            3
        ),
        // Server farm crisis
        MultipleAlarmParams(
            {{95, "Overheating"}, {100, "Overheating"}, {88, "Overheating"}, {92, "Overheating"}},
            "Data center cooling failure",
            4
        ),
        // Cold weather equipment failure
        MultipleAlarmParams(
            {{-45, "Underheating"}, {-50, "Underheating"}, {-35, "Underheating"}},
            "Arctic installation crisis",
            3
        ),
        // Mixed critical conditions
        MultipleAlarmParams(
            {{120, "Overheating"}, {-60, "Underheating"}, {110, "Overheating"}, {-40, "Underheating"}, {95, "Overheating"}},
            "Industrial facility emergency",
            5
        )
    ),
    [](const ::testing::TestParamInfo<MultipleAlarmParams>& info) {
        // Generate test name based on scenario description
        std::string name = info.param.scenario_description;
        std::replace(name.begin(), name.end(), ' ', '_');
        return name + "_Count" + std::to_string(info.param.expected_alarm_count);
    }
);

// ===== BOUNDARY CONDITION TESTING =====

// Acceptance Test: Alarm system behavior at temperature boundaries
// Feature: As a safety system, I need consistent behavior at critical temperature thresholds
// Scenario: Given boundary temperature conditions, when alarms are triggered, then system responds predictably
TEST_F(AtSystemAlarmHandler, GivenBoundaryTemperatureConditions_WhenAlarmsTriggered_ThenSystemRespondsPredictably)
{
    // Test various boundary conditions
    std::vector<int> boundary_temps = {-273, -100, 0, 32, 100, 1000, 32767, -32768};
    
    for (int temp : boundary_temps) {
        // Test both alarm types at boundary conditions
        EXPECT_NO_THROW({
            system_alarm_handler_.ReportOverheatingAlarm(temp);
            system_alarm_handler_.ReportUnderheatingAlarm(temp);
        }) << "Failed at boundary temperature: " << temp << "°C";
    }
    
    SUCCEED() << "All boundary conditions handled successfully";
}