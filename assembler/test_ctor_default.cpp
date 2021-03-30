//  Stack class test program
//
//  Tests: stack default constructor 
//

#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "string.hpp"

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  x;

        // VERIFY
        assert(x.empty());
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  x;

        // VERIFY
        assert(x.empty());
    }
    std::cout << "Done testing stack default constructor." << std::endl;
}

