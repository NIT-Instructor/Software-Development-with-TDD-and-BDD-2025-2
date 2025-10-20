#include "ut_filter.hpp"

// User Story 2.1: Initialize Filter with Default Values
TEST_F(UtFilter, WhenFilterIsCreated_ThenBufferIsAllZero)
{
    for (int i = 0; i < 9; ++i)
    {
        ASSERT_EQ(filter_.buffer_[i], 0);
    }
}

TEST_F(UtFilter, WhenBufferIsAllOnes_ThenReturnOneAsAverageValue)
{
    int expected_value = 1;
    InitializeBuffer(1);
    EXPECT_EQ(filter_.FilterData(), expected_value);
}

// User Story 2.2: Calculate Average for Uniform Data
TEST_F(UtFilter, WhenFilterDataIsCalledWithoutUpdateFilterData_ThenReturnsAverage)
{
    EXPECT_EQ(filter_.FilterData(), 0);
}

// User Story 2.3: Calculate Average for Varying Data
TEST_F(UtFilter, WhenBufferIsPopulatedWithValues_ThenReturnAverageValueOfBufferData)
{
    filter_.buffer_ = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    EXPECT_EQ(filter_.FilterData(), 10);
}

TEST_F(UtFilter, WhenBufferIsPopulatedWith2_ThenReturnAverageValueOf2)
{
    filter_.buffer_ = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    EXPECT_EQ(filter_.FilterData(), 2);
}

TEST_F(UtFilter, WhenBufferIsPopulatedWith43_ThenReturnAverageValueOf43)
{
    filter_.buffer_ = {43, 43, 43, 43, 43, 43, 43, 43, 43};
    EXPECT_EQ(filter_.FilterData(), 43);
}

TEST_F(UtFilter, WhenApplyUpdateFilterWith10_ThenReturnCorrectAverageValueShouldBe10)
{
    InitializeBuffer(1);
    filter_.UpdateFilterData(10);
    filter_.UpdateFilterData(10);
    filter_.UpdateFilterData(10);
    filter_.UpdateFilterData(10);
    filter_.UpdateFilterData(10);
    filter_.UpdateFilterData(10);
    filter_.UpdateFilterData(10);
    filter_.UpdateFilterData(10);
    filter_.UpdateFilterData(10);
    filter_.UpdateFilterData(19);
    filter_.UpdateFilterData(1);
    int expected_value = 10;
    EXPECT_EQ(filter_.FilterData(), expected_value);
}
