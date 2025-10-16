#include "ut_filter.hpp"



// User Story 2.1: Initialize Filter with Default Values
TEST_F(UtFilter, WhenFilterIsCreated_ThenFilterIsNotNullptr)
{
    ASSERT_NE(&filter_, nullptr);
}

TEST_F(UtFilter, WhenFilterIsCreated_ThemSizeOfBufferIsNine)
{
    ASSERT_EQ(sizeof(filter_.buffer_) / sizeof(filter_.buffer_[0]), kBufferSize);
}

TEST_F(UtFilter, WhenFilterIsCreated_ThenBufferShouldBeAllZero)
{
    for (int i = 0; i < kBufferSize; ++i)
    {
        ASSERT_EQ(filter_.buffer_[i], 0);
    }
}

TEST_F(UtFilter, WhenBufferIsAllOnes_ThenReturnOneAsAverageValue)
{
}