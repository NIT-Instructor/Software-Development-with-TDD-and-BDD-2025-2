#pragma once

#include "common.hpp"
#include "filter.hpp"
#include "raw_temp_facade.hpp"
#include "codings.hpp"
#include "system_alarm_handler.hpp"
#include "thermal_reader.hpp"
#include <thread>
#include <chrono>

class HardwareMonitor
{
  public:
    HardwareMonitor(ThermalReader& reader, Codings& codings);
    int Update();
  private : 
    ThermalReader &reader_;
    Codings& codings_;
    std::chrono::steady_clock::time_point last_update_time_;
    static constexpr int kUpdateIntervalMs = 100; 
};