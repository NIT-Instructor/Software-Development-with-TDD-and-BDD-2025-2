#pragma once

#include "system_alarm_handler.hpp"
#include <gtest/gtest.h>

class AtSystemAlarmHandler : public testing::Test {
  public:
    AtSystemAlarmHandler();

  protected:
    SystemAlarmHandler system_alarm_handler_;
};