
#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../../inc/mock_filter.hpp"
#include "../../mock/mock_raw_temp_facade.hpp"
#include "../../inc/thermal_reader.hpp"
#include "../../inc/hardware_monitor.hpp"
#include "../../mock/mock_thermal_reader.hpp"

class UtHardwareMonitor : public ::testing::Test
{
public:
    UtHardwareMonitor();
protected:
    ::testing::NiceMock<MockFilter>        mock_filter_;
    ::testing::NiceMock<MockRawTempFacade> mock_raw_temp_facade_;
    ::testing::NiceMock<MockThermalReader> mock_temperature_reader_;
    Codings codings_;
    HardwareMonitor hardware_monitor_{mock_temperature_reader_, codings_};
};
