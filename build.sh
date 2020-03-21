#!/bin/bash
mkdir -p build
cd src
make all -j$nproc
mv *.o testsolver ../build

