#pragma once 
#include "filter.hpp"
#include <gmock/gmock.h>


class MockFilter : public Filter {

    public:
    
    MOCK_METHOD(int, FilterData, ());


};