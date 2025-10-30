#include "hardware_monitor.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "thermal_reader.hpp"
#include "codings.hpp"
#include "system_alarm_handler.hpp"

class AtHardwareMonitorWithAlarm : public ::testing::Test
{
  public:
    AtHardwareMonitorWithAlarm();


  protected:
    ThermalReader theremal_reader_;
    Filter        filter_;
    RawTempFacade raw_temp_facade_;
    HardwareMonitor hardware_monitor_;
    SystemAlarmHandler mock_alarm_;
    Codings codings_;

};
