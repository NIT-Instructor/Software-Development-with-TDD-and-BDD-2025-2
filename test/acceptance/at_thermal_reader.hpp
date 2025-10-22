#pragma once

#include "thermal_reader.hpp"
#include <gtest/gtest.h>

class AtThermalReader : public testing::Test
{
  public:
    AtThermalReader();

  protected:
    ThermalReader theremal_reader_;
    Filter        filter_;
    RawTempFacade raw_temp_facade_;
};
