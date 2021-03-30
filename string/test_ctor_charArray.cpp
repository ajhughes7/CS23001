//  String class test program
//
//  Tests: char array
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str("");

    // VERIFY
    assert(str.length() == 0);
    assert(str.capacity() == 0);
    assert(str.getStringSize() == 1);
 
  }
  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str("abc");

    // VERIFY
    assert(str.length() == 3);
    assert(str.capacity() == 3);
    assert(str.getStringSize() == 4);
 
  }
  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str("");

    // VERIFY
    assert(str == "");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str("a");

    // VERIFY
    assert(str == "a");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str("hello world");

    // VERIFY
    assert(str == "hello world");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
      
    // TEST
    // Size string of 255
    String  str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

    // VERIFY
    assert(str == "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    // Size string of 256 
    String  str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

    // VERIFY
    assert(str == "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
  }

  // ADD ADDITIONAL TESTS AS NECESSARY
    
  std::cout << "Done testing char Array." << std::endl;

}

