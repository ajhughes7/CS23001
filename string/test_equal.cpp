//  String class test program
//
//  Tests: equal
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
        String  left;
        String  right;

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == true);
        assert(left   == "");
        assert(right  == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("abc");
      String  right("abc");

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == true);
        assert(left   == "abc");
        assert(right  == "abc");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("abcdef");
      String  right("abcdefd");

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == false);
        assert(left   == "abcdef");
        assert(right  == "abcdefd");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("abc");
      String  right("def");

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == false);
        assert(left   == "abc");
        assert(right  == "def");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("abc");
      String  right("abcd");

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == false);
        assert(left   == "abc");
        assert(right  == "abcd");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("abc");
      String  right("ab");

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == false);
        assert(left   == "abc");
        assert(right  == "ab");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left;
      String  right("def");

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == false);
        assert(left   == "");
        assert(right  == "def");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("abc");
      String  right;

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == false);
        assert(left   == "abc");
        assert(right  == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      char  left = 'a';
      String  right("a");

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == true);
        assert(right  == "a");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      char  left = 'a';
      String  right("e");

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == false);
        assert(right  == "e");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      char  left[] = "abc";
      String  right("abc");

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == true);
        assert(right  == "abc");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      char  left[] = "a";
      String  right("");

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == false);
        assert(right  == "");
    }
    
    std::cout << "Done testing equality." << std::endl;
}

