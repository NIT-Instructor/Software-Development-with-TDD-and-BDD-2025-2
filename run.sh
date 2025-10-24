#!/bin/bash

./build/test/unit/TemperatureMonitor_Tests 

TEST_RESULT=$?

# Check if tests failed and return that code
if [ $TEST_RESULT -ne 0 ]; then
  echo "Test failed with exit code $TEST_RESULT"
  exit $TEST_RESULT
else
  echo "All tests passed."
fi

./build/test/acceptance/TemperatureMonitor_AcceptanceTests 

TEST_RESULT=$?

# Check if tests failed and return that code
if [ $TEST_RESULT -ne 0 ]; then
  echo "Test failed with exit code $TEST_RESULT"
  exit $TEST_RESULT
else
  echo "All tests passed."
fi