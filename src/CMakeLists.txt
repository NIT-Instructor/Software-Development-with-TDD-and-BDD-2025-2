set(TARGETLIB "TemperatureMonitor")

set(LIB_SOURCE_FILES 
    thermal_reader.cpp
    filter.cpp
    temperature_utils.cpp
    raw_temp_facade.cpp
    external_c_lib.c)

set(ADDITIONAL_INCLUDE_DIRS ../inc)

add_library(${TARGETLIB} STATIC ${LIB_SOURCE_FILES})
target_include_directories(${TARGETLIB} PUBLIC ${ADDITIONAL_INCLUDE_DIRS})
