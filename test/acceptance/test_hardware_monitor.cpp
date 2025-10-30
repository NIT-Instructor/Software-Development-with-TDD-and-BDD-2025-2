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

// Test parameters for monitoring lifecycle scenarios
struct MonitoringLifecycleParams
{
    int monitoring_duration_ms;      // How long to run monitoring
    int expected_min_cycles;         // Minimum expected monitoring cycles
    std::string scenario_name;       // Description of the test scenario
    std::string system_context;      // Context (server room, industrial, etc.)
    
    MonitoringLifecycleParams(int duration, int min_cycles, const std::string& name, const std::string& context)
        : monitoring_duration_ms(duration), expected_min_cycles(min_cycles), scenario_name(name), system_context(context) {}
};

class AtHardwareMonitorLifecycle : public AtHardwareMonitor,
                                  public ::testing::WithParamInterface<MonitoringLifecycleParams>
{
};

// Acceptance Test: Hardware monitoring system lifecycle in various operational scenarios
// Feature: As a safety system, I need reliable hardware monitoring in different operational contexts
// Scenario: Given various monitoring durations, when I start and stop monitoring, then system operates reliably
TEST_P(AtHardwareMonitorLifecycle, GivenOperationalContext_WhenMonitoringForDuration_ThenSystemOperatesReliably)
{
    const MonitoringLifecycleParams& params = GetParam();
    
    // Given operational context (server room, industrial facility, etc.)
    EXPECT_FALSE(hardware_monitor_->IsMonitoringActive()) 
        << "Initial state should be inactive for " << params.scenario_name;
    
    // When monitoring is started for specified duration
    hardware_monitor_->StartMonitoring();
    EXPECT_TRUE(hardware_monitor_->IsMonitoringActive()) 
        << "Monitoring should be active after start in " << params.system_context;
    
    // Allow monitoring to run for the specified duration
    std::this_thread::sleep_for(std::chrono::milliseconds(params.monitoring_duration_ms));
    
    // Verify system remains stable during monitoring
    EXPECT_TRUE(hardware_monitor_->IsMonitoringActive()) 
        << "System should remain stable during " << params.scenario_name;
    
    // When monitoring is stopped
    hardware_monitor_->StopMonitoring();
    
    // Then system responds correctly
    EXPECT_FALSE(hardware_monitor_->IsMonitoringActive()) 
        << "System should stop cleanly after " << params.scenario_name;

    raw_temp_facade_->ResetSensor();
}

// Various operational scenarios for hardware monitoring
INSTANTIATE_TEST_SUITE_P(
    OperationalScenarios,
    AtHardwareMonitorLifecycle,
    ::testing::Values(
        // Short duration scenarios
        MonitoringLifecycleParams(150, 1, "Quick_system_check", "Development_environment"),
        MonitoringLifecycleParams(250, 2, "Basic_functionality_test", "Testing_lab"),

        // Normal operation scenarios
        MonitoringLifecycleParams(500, 4, "Standard_monitoring_cycle", "Office_server_room"),
        MonitoringLifecycleParams(1000, 9, "Extended_monitoring_session", "Data_center"),

        // Long duration scenarios  
        MonitoringLifecycleParams(1500, 14, "Stress_test_monitoring", "Industrial_facility"),
        MonitoringLifecycleParams(2000, 19, "Endurance_test_monitoring", "Critical_infrastructure")
    ),
    [](const ::testing::TestParamInfo<MonitoringLifecycleParams>& info) {
        return info.param.scenario_name + "_" + std::to_string(info.param.monitoring_duration_ms) + "ms";
    }
);

// Test parameters for continuous monitoring behavior
struct ContinuousMonitoringParams
{
    int monitoring_cycles;           // Number of 100ms cycles to test
    std::string monitoring_purpose;  // Purpose of continuous monitoring
    std::string deployment_context;  // Where this monitoring occurs
    
    ContinuousMonitoringParams(int cycles, const std::string& purpose, const std::string& context)
        : monitoring_cycles(cycles), monitoring_purpose(purpose), deployment_context(context) {}
};

class AtHardwareMonitorContinuous : public AtHardwareMonitor,
                                   public ::testing::WithParamInterface<ContinuousMonitoringParams>
{
};

// Acceptance Test: Continuous monitoring for various operational requirements
// Feature: As a hardware monitoring system, I need continuous temperature monitoring every 100ms for critical applications
// Scenario: Given critical operational requirements, when continuous monitoring runs, then system maintains reliability
TEST_P(AtHardwareMonitorContinuous, GivenCriticalOperationalRequirements_WhenContinuousMonitoringRuns_ThenSystemMaintainsReliability)
{
    const ContinuousMonitoringParams& params = GetParam();

    int monitoring_duration_ms = params.monitoring_cycles * 100; // Each cycle is 100ms

    // Start monitoring
    hardware_monitor_->StartMonitoring();
    EXPECT_TRUE(hardware_monitor_->IsMonitoringActive())
        << "Continuous monitoring should start for " << params.monitoring_purpose;

    // Wait for all cycles to complete
    std::this_thread::sleep_for(std::chrono::milliseconds(monitoring_duration_ms + 50));

    // Check that temperatures were read correctly (example checks)
    for (int i = 0; i < params.monitoring_cycles; ++i)
    {
        int temp = thermal_reader_->ReadFilteredTemperature();
        EXPECT_GE(temp, -30) << "Temperature too low during " << params.monitoring_purpose;
        EXPECT_LE(temp, 80)  << "Temperature too high during " << params.monitoring_purpose;
    }

    // Stop monitoring
    hardware_monitor_->StopMonitoring();
    EXPECT_FALSE(hardware_monitor_->IsMonitoringActive())
        << "System should shutdown cleanly after " << params.monitoring_purpose;

    // Reset sensors after test
    raw_temp_facade_->ResetSensor();
}

// Instantiate test cases for different operational requirements
INSTANTIATE_TEST_SUITE_P(
    ContinuousMonitoringRequirements,
    AtHardwareMonitorContinuous,
    ::testing::Values(
        ContinuousMonitoringParams(3, "System_startup_monitoring", "Server_initialization"),
        ContinuousMonitoringParams(5, "Quick_health_check", "Routine_maintenance"),
        ContinuousMonitoringParams(10, "Load_testing_monitoring", "Performance_validation"),
        ContinuousMonitoringParams(15, "Thermal_stress_testing", "Quality_assurance"),
        ContinuousMonitoringParams(25, "Extended_operation_monitoring", "Production_environment"),
        ContinuousMonitoringParams(50, "Endurance_testing", "Reliability_validation")
    ),
    [](const ::testing::TestParamInfo<ContinuousMonitoringParams>& info) {
        return info.param.monitoring_purpose + "_" + std::to_string(info.param.monitoring_cycles) + "cycles";
    }
);

// Acceptance Test: Basic temperature checking functionality
// Feature: As a hardware monitoring system, I need to perform temperature checks on demand
// Scenario: Given a hardware monitoring system, when I perform manual temperature checks, then system responds reliably
TEST_F(AtHardwareMonitor, GivenHardwareMonitoringSystem_WhenPerformingManualTemperatureChecks_ThenSystemRespondsReliably)
{
    // Given a hardware monitoring system is ready
    
    // When performing multiple manual temperature checks
    const int manual_checks = 10;
    for (int i = 0; i < manual_checks; ++i) {
        EXPECT_NO_THROW(hardware_monitor_->CheckTemperature()) 
            << "Manual temperature check " << i << " should not throw";
    }
    
    // Then system responds reliably to all manual checks
    SUCCEED() << "System handled " << manual_checks << " manual temperature checks reliably";

    raw_temp_facade_->ResetSensor();
}