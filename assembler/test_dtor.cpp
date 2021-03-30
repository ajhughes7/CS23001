//  Stack class test program
//
//  Tests: dtor
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
        stack<String>  x;
	x.push(String("hello"));
	x.push(String("hi"));
	
	x.~stack();

        // VERIFY
	assert(x.empty());
    }
    std::cout << "Done testing dtor." << std::endl;
}

