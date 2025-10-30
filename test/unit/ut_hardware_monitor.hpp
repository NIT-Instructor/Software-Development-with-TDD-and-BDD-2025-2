#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "hardware_monitor.hpp"
#include "mock_thermal_reader.hpp"
#include "mock_codings.hpp"
#include "mock_filter.hpp"
#include "mock_raw_temp_facade.hpp"
#include "mock_system_alarm_handler.hpp"


class UtHardwareMonitor : public ::testing::Test {
    protected:
        HardwareMonitor hardware_monitor;
        ::testing::NiceMock<MockFilter> mock_filter;
        ::testing::NiceMock<MockRawTempFacade> mock_raw_temp_facade;
        ::testing::NiceMock<MockThermalReader> mock_thermal_reader;
        ::testing::NiceMock<MockCodings> mock_codings;
        ::testing::NiceMock<MockSystemAlarmHandler> mock_system_alarm;

    public:
        UtHardwareMonitor();
};