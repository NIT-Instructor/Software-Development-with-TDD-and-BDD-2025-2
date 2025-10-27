#pragma once

#include "common.hpp"
#include "thermal_reader.hpp"
#include "codings.hpp"
#include "system_alarm_handler.hpp"

class HardwareMonitor
{
  public:
    static constexpr int kUpdateIntervalMs = 100;

    HardwareMonitor(ThermalReader& thermal_reader,
                    Codings& codings,
                    SystemAlarmHandler& alarm_handler);
    virtual ~HardwareMonitor() = default;

    MOCKABLE void StartMonitoring();
    MOCKABLE void StopMonitoring();
    MOCKABLE bool IsMonitoringActive() const;

    MOCKABLE void CheckTemperature();
    MOCKABLE bool ValidateCodings() const;

  PRIVATE :
    ThermalReader&       thermal_reader_;
    Codings&             codings_;
    SystemAlarmHandler&  alarm_handler_;
    bool                 is_monitoring_active_{false};
};

