set(TARGETLIB "TemperatureMonitor")

set(LIB_SOURCE_FILES 
    thermal_reader.cpp
    filter.cpp
    temperature_utils.cpp)

set(ADDITIONAL_INCLUDE_DIRS ../inc)

add_library(${TARGETLIB} STATIC ${LIB_SOURCE_FILES})
target_include_directories(${TARGETLIB} PUBLIC ${ADDITIONAL_INCLUDE_DIRS})

if(BUILD_TESTING)
    target_compile_definitions(${TARGETLIB} PRIVATE MOCK_ENABLE TESTING=1)
endif()
