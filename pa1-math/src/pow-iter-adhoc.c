//========================================================================
// pow-iter-adhoc.c
//========================================================================
// This file contains a simple main function using pow_iter function.
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
// % gcc -Wall -Wextra -pedantic -o pow-iter pow-iter-adhoc.c pow-iter.c 
// % ./pow-iter
//

#include <stdio.h>
#include <stdlib.h>
#include "pow-iter.h"

int main() {

  // This is a simple program that calls pow_iter and prints out its result

  float base      = 2.0;
  int   exponent  = 4;
  float result    = pow_iter( base, exponent );

  printf("%f to the power of %d is %f\n", base, exponent, result );

  return 0;
}
