//  String class test program
//
//  Tests: length and capacity
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
        String  str;

        // TEST
        int result = str.capacity();

        // VERIFY
        assert(str    == "");
        assert(result == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");

        // TEST
        int result = str.capacity();

        // VERIFY
        assert(str    == "abc");
        assert(result == 3);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;

        // TEST
        int result = str.length();

        // VERIFY
        assert(str    == "");
        assert(result == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");

        // TEST
        int result = str.length();

        // VERIFY
        assert(str    == "abc");
        assert(result == 3);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;

        // TEST
        int result = str.length();

        // VERIFY
        assert(str    == "");
        assert(result == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); // 255 x's

        // TEST
        int result = str.length();

        // VERIFY
        assert(str    == "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        assert(result == 255);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;

        // TEST
        int result = str.length();

        // VERIFY
        assert(str    == "");
        assert(result == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");
	
        // TEST
        int resultLength = str.length();
	int resultCapacity = str.capacity();
        // VERIFY
	assert(str    == "abc");
	//    capacity()    == stringSize - 1 INV
	assert(resultLength == 3);
        //    length()      == capacity()   INV
        assert(resultLength == resultCapacity);
       
    }
    std::cout << "Done testing length and capacity." << std::endl;
}
