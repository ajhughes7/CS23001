//  String class test program
//
//  Tests: find string
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
      String  str("abcdef");

        // TEST
      int result = str.findstr(0, String("abc"));

        // VERIFY
        assert(str    == "abcdef");
        assert(result == 0);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  str("abcdef");

        // TEST
      int result = str.findstr(5, String("f"));

        // VERIFY
        assert(str    == "abcdef");
        assert(result == 5);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  str("abcdef");

        // TEST
      int result = str.findstr(0, String("xyz"));
        // VERIFY
        assert(str    == "abcdef");
        assert(result == -1);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  str("abcdef");

        // TEST
      int result = str.findstr(3, String("c"));

        // VERIFY
        assert(str    == "abcdef");
        assert(result == -1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  str("ab");

        // TEST
      int result = str.findstr(0, String("abcdef"));

        // VERIFY
        assert(str    == "ab");
        assert(result == -1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  str("ab");

        // TEST
      int result = str.findstr(0, String("b"));

        // VERIFY
        assert(str    == "ab");
        assert(result == 1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  str("ab");

        // TEST
      int result = str.findstr(1, String("b"));

        // VERIFY
        assert(str    == "ab");
        assert(result == 1);
    }

    
    std::cout << "Done testing find string." << std::endl;
}

