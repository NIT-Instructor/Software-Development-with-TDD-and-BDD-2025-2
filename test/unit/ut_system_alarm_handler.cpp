#include "ut_system_alarm_handler.hpp"

UtSystemAlarmHandler::UtSystemAlarmHandler()
    : system_alarm_handler_()
    , original_cout_(nullptr)
{
}

void UtSystemAlarmHandler::SetUp()
{
    // Capture cout output for testing console logging
    original_cout_  = std::cout.rdbuf();
    std::cout.rdbuf(captured_output_.rdbuf());
}

void UtSystemAlarmHandler::TearDown()
{
    // Restore original cout buffer
    std::cout.rdbuf(original_cout_);
}