//========================================================================
// pow-recur-adhoc.c
//========================================================================
// This file contains a simple main function using pow_recur function.
// This file is not included in the CMake build flow, so it needs to
// be built explicitly. This file is used to demonstrate how to build
// a simple C program directly without any build tool such as Makefile
// CMake. Students should use this simple program before attempting
// to use given CMake build tool.
//
// NOTE:
//
// Use the following commannds in the src directory to compile and run
// this adhoc test in the commandline:
//
// % gcc -Wall -Wextra -pedantic -o pow-recur pow-recur-adhoc.c pow-recur.c
// % ./pow-pow-recur
//

#include <stdio.h>
#include <stdlib.h>
#include "pow-recur.h"

int main() {

  // This is a simple program that calls pow_recur and prints out its result

  float base      = 2.0;
  int   exponent  = 4;
  float result    = pow_recur( base, exponent );

  printf("%f to the power of %d is %f\n", base, exponent, result );

  return 0;
}
