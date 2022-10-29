#!/bin/bash
rm MakeFile
cmake CMakeLists.txt
make
./Lab2 --mode=tournament --nameStrategy=ALWAYS_VOICE_C  --nameStrategy=ALWAYS_VOICE_D --nameStrategy=ALWAYS_VOICE_C  --nameStrategy=ALWAYS_VOICE_C  --steps=3
pwd
whoami
