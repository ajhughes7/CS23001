//  String class test program
//
//  Tests: find char
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
        String  str("abc");

        // TEST
        int result = str.findch(0, 'a');

        // VERIFY
        assert(str    == "abc");
        assert(result == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("fabcdef");

        // TEST
        int result = str.findch(1, 'f');

        // VERIFY
        assert(str    == "fabcdef");
        assert(result == 6);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");

        // TEST
        int result = str.findch(0, 'x');

        // VERIFY
        assert(str    == "abc");
        assert(result == -1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");

        // TEST
        int result = str.findch(10, 'a');

        // VERIFY
        assert(str    == "abc");
        assert(result == -1);
    }
     std::cout << "Done testing find char." << std::endl;
}

