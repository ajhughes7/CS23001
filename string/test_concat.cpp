//  String class test program
//
//  Tests: concatenation
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
        String  left;
        String  right;

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "");
        assert(left   == "");
        assert(right  == "");
	assert(result.length() == 0);
	assert(result.capacity() == 0);
	assert(result.getStringSize() == 1);
 
   }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("abc");
      String  right("def");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "abcdef");
        assert(left   == "abc");
        assert(right  == "def");
	assert(result.length() == 6);
	assert(result.capacity() == 6);
	assert(result.getStringSize() == 7);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("");
      String  right("def");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "def");
        assert(left   == "");
        assert(right  == "def");
	assert(result.length() == 3);
	assert(result.capacity() == 3);
	assert(result.getStringSize() == 4);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("abc");
      String  right("");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "abc");
        assert(left   == "abc");
        assert(right  == "");
	assert(result.length() == 3);
	assert(result.capacity() == 3);
	assert(result.getStringSize() == 4);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      // 128 x's plus 128 y's results in 128 x's plus 127 y's due to capacity truncation.

      // update M2: now results in 128 x's plus 128 y's since cap is not an issue.

      String  left("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        String  right("yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy");
        assert(left   == "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        assert(right  == "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      char  left = 'a';
      String  right;

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "a");
        assert(right  == "");

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left[] = "abc";
        String  right;

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "abc");
        assert(right  == "");
	assert(result.length() == 3);
	assert(result.capacity() == 3);
	assert(result.getStringSize() == 4);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left[] = "";
        String  right;

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "");
        assert(right  == "");
	assert(result.length() == 0);
	assert(result.capacity() == 0);
	assert(result.getStringSize() == 1);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");

        // TEST
	str += String("abc");

        // VERIFY
        assert(str  == "abcabc");
	assert(str.length() == 6);
	assert(str.capacity() == 6);
	assert(str.getStringSize() == 7);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");

        // TEST
	str += String("");

        // VERIFY
        assert(str  == "abc");
	assert(str.length() == 3);
	assert(str.capacity() == 3);
	assert(str.getStringSize() == 4);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;

        // TEST
	str += String("abc");

        // VERIFY
        assert(str  == "abc");
    	assert(str.length() == 3);
	assert(str.capacity() == 3);
	assert(str.getStringSize() == 4);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
      std::vector<String> vec;
      
      vec.push_back(String("abc"));
      vec.push_back(String("def"));

      // TEST
      
      String result = vec[0] + vec[1];  
      
      // VERIFY
      assert(result  == "abcdef");
      assert(result.length() == 6);
      assert(result.capacity() == 6);
      assert(result.getStringSize() == 7);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String s("abc def");
      std::vector<String> vec = s.split(' ');
      

      // TEST
      
      String result = vec[0] + vec[1];  
      
      // VERIFY
      assert(result  == "abcdef");
      assert(result.length() == 6);
      assert(result.capacity() == 6);
      assert(result.getStringSize() == 7);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String s("abc def");
      std::vector<String> vec = s.split(' ');
      

      // TEST
      
      String result = vec[0] + vec[1];  
      
      // VERIFY
      assert(result  == "abcdef");
      assert(result.length() == 6);
      assert(result.capacity() == 6);
      assert(result.getStringSize() == 7);
    }
 
 std::cout << "Done testing concat." << std::endl;
}

