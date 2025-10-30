#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mock_filter.hpp"
#include "mock_raw_temp_facade.hpp"
#include "mock_thermal_reader.hpp"
#include "mock_codings.hpp"
#include "mock_system_alarm_handler.hpp"
#include "hardware_monitor.hpp"

class UtHardwareMonitor : public ::testing::Test
{
  public:
    UtHardwareMonitor();

  protected:
    ::testing::NiceMock<MockFilter>               mock_filter_;
    ::testing::NiceMock<MockRawTempFacade>        mock_raw_temp_facade_;
    ::testing::NiceMock<MockThermalReader>        mock_thermal_reader_;
    ::testing::NiceMock<MockCodings>              mock_codings_;
    ::testing::NiceMock<MockSystemAlarmHandler>   mock_system_alarm_handler_;
    HardwareMonitor                               hardware_monitor_;
};