# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp/boost-populate-gitclone-lastrun.txt" AND EXISTS "/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp/boost-populate-gitinfo.txt" AND
  "/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp/boost-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp/boost-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp/boost-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git" 
            clone --no-checkout --progress --config "advice.detachedHead=false" "https://github.com/boostorg/boost.git" "boost-src"
    WORKING_DIRECTORY "/Users/natasamihaleva/projectCXX/Lab2/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/boostorg/boost.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git" 
          checkout "master" --
  WORKING_DIRECTORY "/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'master'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" 
            submodule update --recursive --init tools/cmake;libs/program_options;libs/assert;libs/exception;libs/throw_exception;libs/static_assert;libs/bind;libs/function_types;libs/function;libs/chrono;libs/date_time;libs/concept_check;libs/config;libs/container;libs/container_hash;libs/iterator;libs/utility;libs/type_traits;libs/algorithm;libs/conversion;libs/numeric/conversion;libs/regex;libs/unordered;libs/tokenizer;libs/move;libs/ratio;libs/lexical_cast;libs/tuple;libs/variant2;libs/typeof;libs/detail;libs/array;libs/type_index;libs/range;libs/optional;libs/smart_ptr;libs/integer;libs/rational;libs/intrusive;libs/io;libs/core;libs/align;libs/predef;libs/preprocessor;libs/system;libs/winapi;libs/atomic;libs/mpl;libs/fusion;libs/mp11;libs/any;libs/functional;libs/thread
    WORKING_DIRECTORY "/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp/boost-populate-gitinfo.txt" "/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp/boost-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/Users/natasamihaleva/projectCXX/Lab2/_deps/boost-subbuild/boost-populate-prefix/src/boost-populate-stamp/boost-populate-gitclone-lastrun.txt'")
endif()
