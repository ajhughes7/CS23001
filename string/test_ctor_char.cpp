//  String class test program
//
//  Tests: char constructor 
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
        String  str('a');

        // VERIFY
        assert(str == 'a');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('1');

        // VERIFY
        assert(str == '1');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(' ');

        // VERIFY
        assert(str == ' ');
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing char constructor." << std::endl;

}

