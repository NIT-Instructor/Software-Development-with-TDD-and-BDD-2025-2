#pragma once

#include "thermal_reader.hpp"
#include "hardware_monitor.hpp"
#include "codings.hpp"
#include <gtest/gtest.h>

class AtCodings : public testing::Test
{
  public:
    AtCodings();

  protected:
    ThermalReader theremal_reader_;
    Filter        filter_;
    RawTempFacade raw_temp_facade_;
    HardwareMonitor hardware_monitor_;
    Codings codings_;
};
