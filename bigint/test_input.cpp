/**
 * Andrew Hughes
 * Programming Project 1: bigint Milestone 2
 * CS 23001
 */

// bigint Test Program
//
// Tests: input test
//
//  
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
void inputTest(int expectedValue) {
  bigint bi;
  std::cout << "Enter " << expectedValue << " (; to stop): "; 
  std::cin >> bi;
  assert(bi == expectedValue);
}

int main () {

  inputTest(123);
  inputTest(321);
  inputTest(0);
  inputTest(987654321);  
}

