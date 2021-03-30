/**
 * Andrew Hughes
 * Programming Project 1: bigint Milestone 1
 * CS 23001
 */

// bigint Test Program
//
// Tests: debugPrint 
//
//  
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    // Setup

    // Test 
    bigint bi1;
    bigint bi2(2147483647);

    // Verify
    bi1.debugPrint(std::cout);
    bi2.debugPrint(std::cout);
    assert(true);
}

