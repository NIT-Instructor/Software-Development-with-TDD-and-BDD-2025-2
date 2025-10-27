#pragme once

#include "hardware_monitor.hpp"
#include <gmock/gmock.h>

class MockHardwareMonitor : public HardwareMonitor
{
  public:
    MockHardwareMonitor(ThermalReader& thermal_reader,
                        Codings& codings,
                        SystemAlarmHandler& alarm_handler)
        : HardwareMonitor(thermal_reader, codings, alarm_handler)
    {
    }

    MOCK_METHOD(void, StartMonitoring, (), (override));
    MOCK_METHOD(void, StopMonitoring, (), (override));
    MOCK_METHOD(bool, IsMonitoringActive, (), (const, override));

    MOCK_METHOD(void, CheckTemperature, (), (override));
    MOCK_METHOD(bool, ValidateCodings, (), (const, override));
};