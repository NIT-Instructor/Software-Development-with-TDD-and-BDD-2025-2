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
    filter_.FillBufferWithValue(0);
    for (int i = 0; i < kBufferSize; ++i)
    {
        ASSERT_EQ(filter_.buffer_[i], 0);
    }
}

TEST_F(UtFilter, WhenApplyFilterWithDataAllSetToOnes_ThenReturnOneAsAverageValue)
{
    filter_.FillBufferWithValue(1);
    ASSERT_EQ(filter_.FilterData(), 1);
}

TEST_F(UtFilter, WhenApplyFilterWithDataAllSetToTwo_ThenReturnTwoAsAverageValue)
{
    filter_.FillBufferWithValue(2);
    ASSERT_NE(filter_.FilterData(), 1);
    EXPECT_EQ(filter_.FilterData(), 2);
}

TEST_F(UtFilter, WhenBufferIsFilledWithDifferentValues_ThenReturnsAverageValueOfTheBuffer)
{
    filter_.FillBufferWithValue(1);
    filter_.buffer_[0] = 0;
    filter_.buffer_[1] = 2;
    EXPECT_EQ(filter_.FilterData(), 1);
}

TEST_F(UtFilter, WhenBufferIsFilledWithDifferentValues_ThenReturnsAverageValuesWithDecimals)
{
    filter_.FillBufferWithValue(1);
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


// User Story 2.3: Update Temperature Buffer with New Values
TEST_F(UtFilter, WhenBufferIsFilledWithTemperatureValues_ThenReturnsCorrectAverage)
{
    filter_.buffer_[0] = 20;
    filter_.buffer_[1] = 25;
    filter_.buffer_[2] = 30;
    filter_.buffer_[3] = 15;
    filter_.buffer_[4] = 10;
    filter_.buffer_[5] = 35;
    filter_.buffer_[6] = 40;
    filter_.buffer_[7] = 5;
    filter_.buffer_[8] = 0;

    float expected_average = (20 + 25 + 30 + 15 + 10 + 35 + 40 + 5 + 0) / static_cast<float>(kBufferSize);
    EXPECT_EQ(filter_.FilterData(), expected_average);
}

TEST_F(UtFilter, WhenBufferIsFilledWithNegativeTemperatureValues_ThenReturnsCorrectAverage)
{
    filter_.buffer_[0] = -5.0f;
    filter_.buffer_[1] = -10.0f;
    filter_.buffer_[2] = -15.0f;
    filter_.buffer_[3] = -20.0f;
    filter_.buffer_[4] = -25.0f;
    filter_.buffer_[5] = -30.0f;
    filter_.buffer_[6] = -35.0f;
    filter_.buffer_[7] = -40.0f;
    filter_.buffer_[8] = -45.0f;

    float expected_average = (-5.0f - 10.0f - 15.0f - 20.0f - 25.0f - 30.0f - 35.0f - 40.0f - 45.0f) / static_cast<float>(kBufferSize);
    EXPECT_EQ(filter_.FilterData(), expected_average);
}

TEST_F(UtFilter, WhenBufferIsFilledWithMixedTemperatureValues_ThenReturnsCorrectAverage)
{
    filter_.buffer_[0] = -10.0f;
    filter_.buffer_[1] = 0.0f;
    filter_.buffer_[2] = 7.0f;
    filter_.buffer_[3] = 3.0f;
    filter_.buffer_[4] = -12.0f;
    filter_.buffer_[5] = 4.0f;
    filter_.buffer_[6] = -1.0f;
    filter_.buffer_[7] = 6.0f;
    filter_.buffer_[8] = -2.0f;

    float expected_average = (-10.0f + 0.0f + 7.0f + 3.0f - 12.0f + 4.0f - 1.0f + 6.0f - 2.0f) / static_cast<float>(kBufferSize);
    EXPECT_EQ(filter_.FilterData(), expected_average);
}

TEST_F(UtFilter, WhenBufferIsFilledWithSameTemperatureValues_ThenReturnsThatValueAsAverage)
{
    filter_.FillBufferWithValue(25);

    EXPECT_EQ(filter_.FilterData(), 25.0f);
}

TEST_F(UtFilter, WhenAllTemperaturesIncreaseByFive_ThenAverageIncreasesByFive)
{
    filter_.buffer_[0] = 10;
    filter_.buffer_[1] = 15;
    filter_.buffer_[2] = 20;
    filter_.buffer_[3] = 25;
    filter_.buffer_[4] = 30;
    filter_.buffer_[5] = 35;
    filter_.buffer_[6] = 40;
    filter_.buffer_[7] = 45;
    filter_.buffer_[8] = 50;

    float initial_average = filter_.FilterData();

    for (int i = 0; i < kBufferSize; ++i)
    {
        filter_.buffer_[i] += 5;
    }

    float new_average = filter_.FilterData();
    EXPECT_EQ(new_average, initial_average + 5);
}