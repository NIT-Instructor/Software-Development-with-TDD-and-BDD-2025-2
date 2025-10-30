#pragma once

#include "hardware_monitor.hpp"
#include "thermal_reader.hpp"
#include "filter.hpp"
#include "raw_temp_facade.hpp"
#include "codings.hpp"
#include "system_alarm_handler.hpp"

#include <gtest/gtest.h>

class AtHardwareMonitor : public ::testing::Test
{
  public:
    AtHardwareMonitor();
  protected:
    ThermalReader theremal_reader_;
    Filter        filter_;
    RawTempFacade raw_temp_facade_;
    Codings       codings_;
    SystemAlarmHandler system_alarm_handler_;
    HardwareMonitor hardware_monitor_;
};