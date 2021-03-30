//  String class test program
//
//  Tests: copy constructor
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================

String appendX(String s) {
  s = s + "x";
  return s;
}



int main () {
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s0("abc");
        // TEST
       
        String s1 = appendX(s0);

        // VERIFY
        assert(s0 == "abc");
	assert(s1 == "abcx");
    }
  
    std::cout << "Done testing copy constructor." << std::endl;

}

