#=========================================================================
# CMake script for PA1
#=========================================================================
# Author: Tuan Ta, Yanghui Ou
# Date  : Sep 2019
#

#-------------------------------------------------------------------------
# List of implementations in this PA
#-------------------------------------------------------------------------
# Please add any new implementation to the list. The implementation's name
# does not include any file extension (e.g., ".c" and ".cpp").

set(IMPLS pow-iter
          pow-recur
          sqrt-iter
          sqrt-recur)

#-------------------------------------------------------------------------
# List of unit tests in this PA
#-------------------------------------------------------------------------
# Please add any new test to the list. The test's name does not include
# any file extension (e.g., ".c" and ".cpp").

set(TESTS pow-iter-basic-test
          pow-iter-directed-test
          pow-iter-random-test
          sqrt-iter-basic-test
          sqrt-iter-directed-test
          sqrt-iter-random-test
          pow-recur-basic-test
          pow-recur-directed-test
          pow-recur-random-test
          sqrt-recur-basic-test
          sqrt-recur-directed-test
          sqrt-recur-random-test)

#-------------------------------------------------------------------------
# !!!!DO NOT TOUCH THE FOLLOWING CODE!!!!
#-------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.8)
enable_language(C)

# ctest configs
include(CTest)
enable_testing()

# Set a default build type if none was specified
set(default_build_type "Debug")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)

  # Set the possible values of build type
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Eval" )
endif()

# Flags for GCC
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic-errors -Werror")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g --coverage")
set(CMAKE_C_FLAGS_EVAL "-O3")

# Path to this PA's source files
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test")

# Include path to this PA's header files
include_directories(${SRC_DIR})

#-------------------------------------------------------------------------
# Prepares a list of testing targets for each implementation
#-------------------------------------------------------------------------

foreach(TEST ${TESTS})

  # Extract app names from test names
  # assuming test names are in the following format
  # {implementation's name}-{implementation's version}-{test's name}-tests

  string(REPLACE "-" ";" TOKENS ${TEST})
  list(REMOVE_AT TOKENS 2 3)
  string(REPLACE ";" "-" SRC "${TOKENS}")

  # Get source files
  set(IMPL_SRC "${SRC_DIR}/${SRC}.c")
  set(TEST_SRC "${TEST_DIR}/${TEST}.c")

  # Add tests
  add_executable(${TEST} ${TEST_SRC} ${IMPL_SRC})
  target_link_libraries(${TEST} m)
  add_test(${TEST} ${TEST})

endforeach(TEST)

# Add a target to run all tests using ctest
add_custom_target(check
                  COMMAND echo "Running all unit tests ..."
                  COMMAND ctest "--test-timeout=10"
                  DEPENDS ${TESTS})
