//  String class test program
//
//  Tests: split
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <vector>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;

        // TEST
	std::vector<String> result = str.split(' ');

        // VERIFY
        assert(str    == "");
        assert(result.size() == 1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc ef gh");

        // TEST
	std::vector<String> result = str.split(' ');
	//std::cout << result.size() << std::endl;

        // VERIFY
        assert(str    == "abc ef gh");
	assert(result.size() == 3);
       	assert(result[0] == "abc");
       	assert(result[1] == "ef");
	assert(result[2] == "gh");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("-a--b-");

        // TEST
	std::vector<String> result = str.split('-');
	//std::cout << result.size() << std::endl;

        // VERIFY
        assert(str    == "-a--b-");
	assert(result.size() == 5);
       	assert(result[0] == "");
       	assert(result[1] == "a");
	assert(result[2] == "");
	assert(result[3] == "b");
	assert(result[4] == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("xxxxx");

        // TEST
	std::vector<String> result = str.split('x');
	// std::cout << result.size() << std::endl;

        // VERIFY
        assert(str    == "xxxxx");
	assert(result.size() == 6); 
	assert(result[0] == "");
	assert(result[1] == "");
	assert(result[2] == "");
	assert(result[3] == "");
	assert(result[4] == "");
	assert(result[5] == "");	
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");

        // TEST
	std::vector<String> result = str.split(' ');
	//std::cout << result.size() << std::endl;

        // VERIFY
        assert(str    == "abc");
	assert(result.size() == 1);
       	assert(result[0] == "abc");
    }
    std::cout << "Done testing split." << std::endl;
}


