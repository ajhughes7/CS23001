// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
  {
    // Setup
    bigint bi(4);	
    // Test 
    int digit = bi[0];
    // Verify
    assert(bi    == 4);
    assert(digit == 4);
  }
  {
    // Setup
    bigint bi(10);	
    // Test 
    int digit = bi[1];
    // Verify
    assert(bi    == 10);
    assert(digit == 1);
  }
  {
    // Setup
    bigint bi(324);	
    // Test 
    int digit = bi[2];
    // Verify
    assert(bi    == 324);
    assert(digit == 3);
  }
  {
    // Setup
    bigint bi(4563219);	
    // Test 
    int digit = bi[6];
    // Verify
    assert(bi    == 4563219);
    assert(digit == 4);
  }
    
  {
    // Setup
    bigint bi(45);	
    // Test 
    int digit = bi[0];
    // Verify
    assert(bi    == 45);
    assert(digit == 5);
  }
  {
    // Setup
    bigint bi(54);	
    // Test 
    int digit = bi[9];
    // Verify
    assert(bi    == 54);
    assert(digit == 0);
  }


    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
}

