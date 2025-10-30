#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "system_alarm_handler.hpp"

class UtSystemAlarmHandler : public ::testing::Test {
  public:
    UtSystemAlarmHandler();

  protected:
    SystemAlarmHandler system_alarm_handler_;
};