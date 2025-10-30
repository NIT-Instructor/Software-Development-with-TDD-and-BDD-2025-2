#pragma once

#include "hardware_monitor.hpp"
#include "thermal_reader.hpp"
#include "codings.hpp"
#include "system_alarm_handler.hpp"
#include <gtest/gtest.h>

class AtHardwareMonitor : public testing::Test
{
  protected:
    void SetUp() override
    {
        filter_ = std::make_unique<Filter>();
        raw_temp_facade_ = std::make_unique<RawTempFacade>();
        thermal_reader_ = std::make_unique<ThermalReader>(*filter_, *raw_temp_facade_);
        codings_ = std::make_unique<Codings>();
        system_alarm_handler_ = std::make_unique<SystemAlarmHandler>();
        hardware_monitor_ = std::make_unique<HardwareMonitor>(*thermal_reader_, *codings_, *system_alarm_handler_);
    }

    void TearDown() override
    {
        if(hardware_monitor_)
        {
            hardware_monitor_->StopMonitoring();
        }
    }
    std::unique_ptr<HardwareMonitor> hardware_monitor_;
    std::unique_ptr<ThermalReader> thermal_reader_;
    std::unique_ptr<Filter>        filter_;
    std::unique_ptr<RawTempFacade> raw_temp_facade_;
    std::unique_ptr<Codings> codings_;
    std::unique_ptr<SystemAlarmHandler> system_alarm_handler_;
};
