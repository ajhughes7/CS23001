//  String class test program
//
//  Tests: concatenation
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
	str = String("def");

        // VERIFY
        assert(str  == "def");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");

        // TEST
	str = String("");

        // VERIFY
        assert(str  == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;

        // TEST
	str = String("abc");

        // VERIFY
        assert(str  == "abc");
    }

  std::cout << "Done testing assign." << std::endl;
}

