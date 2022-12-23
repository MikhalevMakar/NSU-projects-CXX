# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/natasamihaleva/projectCXX/Lab4/cmake-build-debug/_deps/boost-src"
  "/Users/natasamihaleva/projectCXX/Lab4/cmake-build-debug/_deps/boost-build"
  "/Users/natasamihaleva/projectCXX/Lab4/cmake-build-debug/_deps/boost-subbuild/boost-populate-prefix"
  "/Users/natasamihaleva/projectCXX/Lab4/cmake-build-debug/_deps/boost-subbuild/boost-populate-prefix/tmp"
  "/Users/natasamihaleva/projectCXX/Lab4/cmake-build-debug/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp"
  "/Users/natasamihaleva/projectCXX/Lab4/cmake-build-debug/_deps/boost-subbuild/boost-populate-prefix/src"
  "/Users/natasamihaleva/projectCXX/Lab4/cmake-build-debug/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/natasamihaleva/projectCXX/Lab4/cmake-build-debug/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp/${subDir}")
endforeach()
