#pragma once

#include "common.hpp"
#include "thermal_reader.hpp"
#include "codings.hpp"
#include "system_alarm_handler.hpp"
#include <thread>
#include <atomic>
#include <chrono>

class HardwareMonitor
{
  public:
    static constexpr int kUpdateIntervalMs = 100;

    HardwareMonitor(ThermalReader& thermal_reader,
                    Codings& codings,
                    SystemAlarmHandler& alarm_handler);
    virtual ~HardwareMonitor();

    MOCKABLE void StartMonitoring();
    MOCKABLE void StopMonitoring();
    MOCKABLE bool IsMonitoringActive() const;
    
  PRIVATE :
    MOCKABLE void CheckTemperature() const;
    MOCKABLE bool ValidateCodings() const;
    void MonitoringLoop();

    ThermalReader&       thermal_reader_;
    Codings&             codings_;
    SystemAlarmHandler&  alarm_handler_;
    std::atomic<bool>    is_monitoring_active_;
    std::thread          monitoring_thread_;
};

