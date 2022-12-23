# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.23.2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(boost-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[/usr/bin/git]==])
set(GIT_VERSION_STRING [==[2.37.0 (Apple Git-136)]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[/usr/bin/git;2.37.0 (Apple Git-136)]==]
)


include(ExternalProject)
ExternalProject_Add(boost-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_SUBMODULES" "tools/cmake" "libs/program_options" "libs/assert" "libs/exception" "libs/throw_exception" "libs/static_assert" "libs/bind" "libs/function_types" "libs/function" "libs/chrono" "libs/date_time" "libs/concept_check" "libs/config" "libs/container" "libs/container_hash" "libs/iterator" "libs/utility" "libs/type_traits" "libs/algorithm" "libs/conversion" "libs/numeric/conversion" "libs/regex" "libs/unordered" "libs/tokenizer" "libs/move" "libs/ratio" "libs/lexical_cast" "libs/tuple" "libs/variant2" "libs/typeof" "libs/detail" "libs/array" "libs/type_index" "libs/range" "libs/optional" "libs/smart_ptr" "libs/integer" "libs/rational" "libs/intrusive" "libs/io" "libs/core" "libs/align" "libs/predef" "libs/preprocessor" "libs/system" "libs/winapi" "libs/atomic" "libs/mpl" "libs/fusion" "libs/mp11" "libs/any" "libs/functional" "libs/thread" "GIT_PROGRESS" "TRUE" "GIT_REPOSITORY" "https://github.com/boostorg/boost.git"
                    SOURCE_DIR          "/Users/natasamihaleva/projectCXX/Lab4/cmake-build-debug/_deps/boost-src"
                    BINARY_DIR          "/Users/natasamihaleva/projectCXX/Lab4/cmake-build-debug/_deps/boost-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


