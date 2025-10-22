set(BINARY TemperatureMonitor_AcceptanceTests)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false test_*.cpp at_*.cpp)
add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC 
    gtest
    TemperatureMonitor
)
