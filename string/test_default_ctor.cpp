//  String class test program
//
//  Tests: default constructor
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
        String  str;

        // VERIFY
        assert(str == "");
    }

    std::cout << "Done testing default constructor." << std::endl;

}

