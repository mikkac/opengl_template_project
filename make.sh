#!/bin/bash
cd ./build
cmake ..
make -j8
mv template ..
cd ..
./template

