#pragma once

#include "hardware_monitor.hpp"
#include <gtest/gtest.h>

class AtHardwareMonitor : public ::testing::Test
{
  public:
    AtHardwareMonitor();
  protected:
    HardwareMonitor hardware_monitor_;
};