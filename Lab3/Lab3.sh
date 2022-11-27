#!/bin/bash
rm MakeFile
cmake CMakeLists.txt
make
./Lab3 --help
whoami