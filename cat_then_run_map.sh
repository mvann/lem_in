#!/bin/bash

echo "--- MAP ---" &&\
cat -e $1 &&\
echo "--- ./lem-in ---" &&\
./lem-in < $1
