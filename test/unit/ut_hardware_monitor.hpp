#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "hardware_monitor.hpp"

class UtHardwareMonitor : public ::testing::Test
{
  public:
    UtHardwareMonitor();

  protected:
    HardwareMonitor hardware_monitor_;
};