#include "ut_filter.hpp"

// User Story 2.1: Initialize Filter with Default Values
// TEST_F(UtFilter, WhenFilterIsCreated_ThenBufferShouldBeAllZero)
// {
//     for (int i = 0; i < 9; ++i)
//     {
//         ASSERT_EQ(filter_.buffer_[i], 0);
//     }
// }

TEST_F(UtFilter, WhenFilterIsCreated_ThenBufferShouldBeAllOne)
{
    for (int i = 0; i < 9; ++i)
    {
        ASSERT_EQ(filter_.buffer_[i], 1);
    }
}

TEST_F(UtFilter, WhenBufferIsAllOnes_ThenReturnOneAsAverageValue)
{
    uint8_t result = filter_.FilterData();
    ASSERT_EQ(result, 1);

}