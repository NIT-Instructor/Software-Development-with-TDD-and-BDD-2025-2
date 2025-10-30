#pragma once

#include "system_alarm_handler.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

class UtSystemAlarmHandler : public ::testing::Test
{
    public:
        UtSystemAlarmHandler();
        void SetUp() override;
        void TearDown() override;

    protected:
        SystemAlarmHandler system_alarm_handler_;
        std::streambuf*    original_cout_;
        std::ostringstream captured_output_;
};