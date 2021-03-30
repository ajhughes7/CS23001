// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
  {

    // updated set of tests.


    //------------------------------------------------------
    // Setup fixture
    bigint left(0);
    bigint right(0);
    bigint result;

    // Test 
    result = left + right;

    // Verify
    assert(left   == 0);
    assert(right  == 0);
    assert(result == 0);
  }
  {
    //------------------------------------------------------
    // Setup fixture
    bigint left(1);
    bigint right(0);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left   == 1);
    assert(right  == 0);
    assert(result == 1);
  }
  {
    //------------------------------------------------------
    // Setup fixture
    bigint left(1);
    bigint right(1);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left   == 1);
    assert(right  == 1);
    assert(result == 2);
  }
  {
    //------------------------------------------------------
    // Setup fixture
    bigint left(9);
    bigint right(5);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left   ==  9);
    assert(right  ==  5);
    assert(result == 14);
  } 
  {
    //------------------------------------------------------
    // Setup fixture
    bigint left(900);
    bigint right(500);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left   ==  900);
    assert(right  ==  500);
    assert(result == 1400);
  }
  {
    //------------------------------------------------------
    // Setup fixture
    bigint left(1);
    bigint right(999);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left   ==  1);
    assert(right  ==  999);
    assert(result == 1000);
  }

  {
      //------------------------------------------------------
      // Setup fixture
      bigint left("90000000");
      bigint right("50000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==  "90000000");
      assert(right  ==  "50000000");
      assert(result == "140000000");
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("90000000");
      bigint right("50000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==  "90000000");
      assert(right  ==  "50000000");
      assert(result == "140000000");
    }
    { 
      //------------------------------------------------------
      // Setup fixture
      bigint left("9000000000");
      bigint right("5000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==  "9000000000");
      assert(right  ==  "5000000000");
      assert(result == "14000000000");
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("900000000000000");
      bigint right("500000000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==  "900000000000000");
      assert(right  ==  "500000000000000");
      assert(result == "1400000000000000");
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("900000000000000");
      bigint right("500000000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==  "900000000000000");
      assert(right  ==  "500000000000000");
      assert(result == "1400000000000000");
    }
    {
    //------------------------------------------------------
    // Setup fixture
    bigint left("90000000000000000000");
    bigint right("50000000000000000000");
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left   ==  "90000000000000000000");
    assert(right  ==  "50000000000000000000");
    assert(result == "140000000000000000000");
    } 
    std::cout << "Done with testing addition." << std::endl;
}

