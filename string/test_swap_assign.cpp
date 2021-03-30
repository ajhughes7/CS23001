//  String class test program
//
//  Tests: swap
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
        String  s1("a");
	String  s2("b");
        // TEST
        s1.swap(s2);

        // VERIFY
        assert(s2 == "a");
	assert(s1 == "b");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  s1;
	String  s2("b");
        // TEST
        s1.swap(s2);

        // VERIFY
        assert(s2 == "");
	assert(s1 == "b");
    }
    


    std::cout << "Done testing swap." << std::endl;

}

