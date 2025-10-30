#pragma once

#include "hardware_monitor.hpp"
#include <gtest/gtest.h>

class AtHardwareMonitor : public testing::Test {

  public:
    AtHardwareMonitor();

  protected:
    HardwareMonitor hardware_monitor;
    ThermalReader thermal_reader;
    Codings codings;
    SystemAlarmHandler system_alarm_handler;
    Filter filter;
    RawTempFacade raw_temp_facade;

};