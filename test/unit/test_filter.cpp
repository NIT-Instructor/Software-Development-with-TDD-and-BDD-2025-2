#include "ut_filter.hpp"

// User Story 2.1: Initialize Filter with Default Values
TEST_F(UtFilter, WhenFilterIsCreated_ThenBufferShouldBeAllZero)
{
    for (int i = 0; i < 9; ++i)
    {
        ASSERT_EQ(filter_.buffer_[i], 0);
    }
}

TEST_F(UtFilter, WhenBufferIsAllOnes_ThenReturnOneAsAverageValue)
{
    InitializeBuffer(1);
    for (int i = 0; i < 9; i++)
    {
        ASSERT_EQ(filter_.buffer_[i], 1);
    }
}