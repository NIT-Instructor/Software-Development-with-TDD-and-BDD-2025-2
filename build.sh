#!/bin/bash

if [ ! -d "build" ];
then 
    mkdir build
fi

cd build 
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCODE_COVERAGE=ON -DTESTING=ON
make