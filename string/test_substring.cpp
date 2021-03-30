//  String class test program
//
//  Tests: substring 
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
        String  str("abcdef");

        // TEST
        String result = str.substr(2, 4);

        // VERIFY
        assert(str    == "abcdef");
        assert(result == "cde");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdef");

        // TEST
        String result = str.substr(2, 2);
	//	std::cout << result << std::endl;
        // VERIFY
        assert(str    == "abcdef");
        assert(result == "c");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdef");
      
        // TEST
        String result = str.substr(0, 5);
      
        // VERIFY
        assert(str    == "abcdef");
        assert(result == "abcdef");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("ab");

        // TEST
        String result = str.substr(0, 1);

        // VERIFY
        assert(str    == "ab");
        assert(result == "ab");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("a");

        // TEST
        String result = str.substr(0, 0);

        // VERIFY
        assert(str    == "a");
        assert(result == "a");
    }
    

    std::cout << "Done testing substring." << std::endl;
}

