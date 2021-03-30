//  String class test program
//
//  Tests: input/ output
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

	std::cout<< "abc should follow: " << str << std::endl;
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;

	std::cout<< "enter the string abc: ";
	std::cin>> str;

	assert(str == "abc");
    }
    
    std::cout << "Done testing input/ output." << std::endl;
}

