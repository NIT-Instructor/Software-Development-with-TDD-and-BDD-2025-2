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

TEST_F(UtFilter, WhenBufferIsAllOnes_ThenReturnNotEqualFiveAsAvarageValue)
{
    uint8_t result = filter_.FilterData();
    ASSERT_NE(result, 5);
}

TEST_F(UtFilter, WhenBufferIsAllFive_ThenReturnFiveAsAvarageValue)
{
    filter_.UpdateFilterData(5);
    uint8_t result = filter_.FilterData();
    ASSERT_EQ(result, 5);
}

TEST_F(UtFilter, WhenBufferIsAllDifferent_ThenReturnTwoAsAvarageValue)
{
    filter_.UpdateFilterData(2);
    filter_.buffer_[2] = 2;
    filter_.buffer_[5] = 2;
    uint8_t result = filter_.FilterData();
    ASSERT_EQ(result, 2);
}

TEST_F(UtFilter, WhenBufferHasPositiveValues_ThenAverageShouldBeGreaterThanZero)
{
    filter_.UpdateFilterData(6);
    uint8_t result = filter_.FilterData();
    ASSERT_GT(result, 0);
}

TEST_F(UtFilter, WhenBufferIsUniform_ThenAverageShouldNotExceedValue)
{
    filter_.UpdateFilterData(4);
    uint8_t result = filter_.FilterData();
    ASSERT_LE(result, 4);
}

TEST_F(UtFilter, WhenBufferIsFilledWithDifferentValues_ThenAverageShouldBeCalculeted)
{
    filter_.buffer_[0] = 38;
    filter_.buffer_[1] = 40;
    filter_.buffer_[2] = 39;
    filter_.buffer_[3] = 38;
    filter_.buffer_[4] = 40;
    filter_.buffer_[5] = 41;
    filter_.buffer_[6] = 35;
    filter_.buffer_[7] = 37;
    filter_.buffer_[8] = 40;

    uint16_t sum = 0; 

    for( int i = 0; i < 9; i++) 
    {
        sum += filter_.buffer_[i];
    }

    sum = sum / kBufferSize;

    EXPECT_EQ(filter_.FilterData(), sum);
}

