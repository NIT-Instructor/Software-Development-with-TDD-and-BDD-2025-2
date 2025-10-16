#include "filter.hpp"

Filter::Filter()
{
    for(int i = 0; i < 9; i++)
    {
        buffer_[i] = 0;
    }
}
// Filter class constructor and FilterData method to be implemented by students
