//  String class test program
//
//  Tests: subscript
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
        String  str("a");

        // TEST
        char result = str[0];

        // VERIFY
        assert(str    == "a");
	assert(result == 'a');
    }
   {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");

        // TEST
        char result = str[2];

        // VERIFY
        assert(str    == "abc");
	assert(result == 'c');
    }

   {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");
        str[1] = 'x';

        // TEST
        char result = str[1];

        // VERIFY
        assert(str    == "axc");
	assert(result == 'x');
    }
   {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");
        str[1] = 'c';
        // TEST
        char result = str[2];

        // VERIFY
        assert(str    == "acc");
	assert(result == 'c');
    }


    
    std::cout << "Done testing subscript." << std::endl;
}

