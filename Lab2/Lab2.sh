#!/bin/bash
rm MakeFile
cmake CMakeLists.txt
make
./Lab2 --mode=tournament --nameStrategy=ALWAYS_VOICE_C  --nameStrategy=ALWAYS_VOICE_D  --nameStrategy=PERCENTAGE_CHOICE --configs=configFile1.txt --gameMatrix=matrix.txt
pwd
whoami
