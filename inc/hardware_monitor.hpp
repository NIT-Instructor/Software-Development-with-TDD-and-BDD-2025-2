#pragma once

#include "common.hpp"
#include "filter.hpp"
#include "raw_temp_facade.hpp"
#include "thermal_reader.hpp"
#include <thread>
#include <chrono>

class HardwareMonitor
{
  public:
    HardwareMonitor(ThermalReader& reader);
    void Update();
  private : 
    ThermalReader &reader_;
    std::chrono::steady_clock::time_point last_update_time_;
    static constexpr int kUpdateIntervalMs = 100; 
};