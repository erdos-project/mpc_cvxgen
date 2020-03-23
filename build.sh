#!/bin/bash
mkdir -p build
cd src || return
make clean
make all
mv ./*.o ./*.so testsolver ../build
