#=========================================================================
# CMake script for PA1
#=========================================================================
# To add new implementations or new tests, simply append your new file to
# the corresponding list.
#
# Author: Yanghui Ou
#   Date: Sep 15, 2019
#

set(SRC_FILES
  pow-iter.c
  pow-recur.c
  sqrt-iter.c
  sqrt-recur.c
)

set(TEST_MILESTONE_FILES
  pow-iter-basic-test.c
  pow-iter-directed-test.c
  pow-iter-random-test.c
  sqrt-iter-basic-test.c
  sqrt-iter-directed-test.c
  sqrt-iter-random-test.c
)

set(TEST_ALL_FILES
  ${TEST_MILESTONE_FILES}
  pow-recur-basic-test.c
  pow-recur-directed-test.c
  pow-recur-random-test.c
  sqrt-recur-basic-test.c
  sqrt-recur-directed-test.c
  sqrt-recur-random-test.c
)

set (EVAL_FILES
  pow-iter-eval.c
  pow-recur-eval.c
  pow-std-eval.c
  sqrt-iter-eval.c
  sqrt-recur-eval.c
  sqrt-std-eval.c
)

#=========================================================================
# !!!!DO NOT TOUCH THE FOLLOWING CODE!!!!
#=========================================================================

#-------------------------------------------------------------------------
# remove_extension
#-------------------------------------------------------------------------
# Removes the file extension. For example:
# remove_extension(IMPL, "pow-iter.c") stores "pow-iter" into IMPL.

function(remove_extension VARNAME FILE_NAME)
  string(REGEX REPLACE "\\.[^.]*$" "" NAME_WITHOUT_EXT ${FILE_NAME})
  set(${VARNAME} "${NAME_WITHOUT_EXT}" PARENT_SCOPE)
endfunction()

#-------------------------------------------------------------------------
# Set up environment
#-------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.8)
enable_language(C)
enable_testing()
project(pa1-math)

# Set and cache the build type
set(default_build_type "debug")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "debug" "eval" )

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "${default_build_type}")
endif()
message(STATUS "Setting build type to '${CMAKE_BUILD_TYPE}'")

# Flags for GCC
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic-errors -Werror")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g --coverage")
set(CMAKE_C_FLAGS_EVAL "-O3")

# Path to this PA's source files
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test")
set(EVAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/eval")

# Include path to this PA's header files
include_directories(${SRC_DIR})

#-------------------------------------------------------------------------
# Link source files into a library
#-------------------------------------------------------------------------

foreach(SRC_FILE ${SRC_FILES})
  set(LIB_SRCS ${LIB_SRCS} "${SRC_DIR}/${SRC_FILE}")
endforeach(SRC_FILE)

add_library(lib${PROJECT_NAME} ${LIB_SRCS})

#-------------------------------------------------------------------------
# Test targets
#-------------------------------------------------------------------------

add_custom_target(check COMMAND ctest "--test-timeout=10")

foreach(TEST_FILE ${TEST_ALL_FILES})

  remove_extension(TEST_BIN ${TEST_FILE})
  set(TEST_SRC "${TEST_DIR}/${TEST_FILE}")

  # Add test
  add_executable(${TEST_BIN} EXCLUDE_FROM_ALL ${TEST_SRC})
  target_link_libraries(${TEST_BIN} m libpa1-math) # link the math and src library
  add_dependencies(check ${TEST_BIN})
  add_test(${TEST_BIN} ${TEST_BIN})

endforeach(TEST_FILE)

#-------------------------------------------------------------------------
# Milestone test targets
#-------------------------------------------------------------------------

add_custom_target(check-milestone COMMAND ctest "-L" "milestone" "--test-timeout=10")

foreach(TEST_FILE ${TEST_MILESTONE_FILES})

  remove_extension(TEST_BIN ${TEST_FILE})
  add_dependencies(check-milestone ${TEST_BIN})
  set_tests_properties(${TEST_BIN} PROPERTIES LABELS "milestone")

endforeach(TEST_FILE)

#-------------------------------------------------------------------------
# Evaluation targets
#-------------------------------------------------------------------------

add_custom_target(eval)

foreach(EVAL_FILE ${EVAL_FILES})

  remove_extension(EVAL_BIN ${EVAL_FILE})
  set(EVAL_SRC "${EVAL_DIR}/${EVAL_FILE}")

  # Add eval
  add_executable(${EVAL_BIN} EXCLUDE_FROM_ALL ${EVAL_SRC})
  target_link_libraries(${EVAL_BIN} m libpa1-math) # link the math and src library
  add_dependencies(eval ${EVAL_BIN})

endforeach(EVAL_FILE)

#-------------------------------------------------------------------------
# Code coverage target
#-------------------------------------------------------------------------

add_custom_target(coverage
  COMMAND lcov --capture --directory . --output-file coverage.info
  COMMAND genhtml coverage.info --output-directory coverage-html
)
