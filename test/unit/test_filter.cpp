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


// User Story 2.2: Calculate Average Value from Buffer
TEST_F(UtFilter, WhenApplyFilterWithDataAllSetToZeros_ThenReturnZeroAsAverageValue)
{
    ASSERT_EQ(filter_.FilterData(), 0);
}

TEST_F(UtFilter, WhenBufferIsAllZeros_ThenEveryPartOfBufferIsZero)
{
    filter_.FillBufferWithWalue(0);
    for (int i = 0; i < kBufferSize; ++i)
    {
        ASSERT_EQ(filter_.buffer_[i], 0);
    }
}

TEST_F(UtFilter, WhenApplyFilterWithDataAllSetToOnes_ThenReturnOneAsAverageValue)
{
    filter_.FillBufferWithWalue(1);
    ASSERT_EQ(filter_.FilterData(), 1);
}

TEST_F(UtFilter, WhenApplyFilterWithDataAllSetToTwo_ThenReturnTwoAsAverageValue)
{
    filter_.FillBufferWithWalue(2);
    ASSERT_NE(filter_.FilterData(), 1);
    EXPECT_EQ(filter_.FilterData(), 2);
}

TEST_F(UtFilter, WhenBufferIsFilledWithDifferentValues_ThenReturnsAverageValueOfTheBuffer)
{
    filter_.FillBufferWithWalue(1);
    filter_.buffer_[0] = 0;
    filter_.buffer_[1] = 2;
    EXPECT_EQ(filter_.FilterData(), 1);
}

TEST_F(UtFilter, WhenBufferIsFilledWithDifferentValues_ThenReturnsAverageValuesWithDecimals)
{
    filter_.FillBufferWithWalue(1);
    filter_.buffer_[0] = 0;
    filter_.buffer_[1] = 3;

    float average = 0.0f;

    for (const auto &item : filter_.buffer_)
    {
        average += item;
    }

    average /= kBufferSize;

    EXPECT_EQ(average, filter_.FilterData());
}