set(TARGETLIB "TemperatureMonitor")

set(LIB_SOURCE_FILES 
    temperature_utils.cpp)

set(ADDITIONAL_INCLUDE_DIRS ../inc)

add_library(${TARGETLIB} STATIC ${LIB_SOURCE_FILES})
target_include_directories(${TARGETLIB} PUBLIC ${ADDITIONAL_INCLUDE_DIRS})
