#!/bin/bash

lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch
lcov --remove coverage.info '/usr/*' '*/test/*' --output-file coverage.filtered.info

genhtml coverage.filtered.info --output-directory coverage-report