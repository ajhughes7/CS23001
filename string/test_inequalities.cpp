//  String class test program
//
//  Tests: less than
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
        String  left;
        String  right;

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(left   == "");
        assert(right  == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("ab");
      String  right("abc");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(left   == "ab");
        assert(right  == "abc");
    }
     {
        //------------------------------------------------------
        // SETUP FIXTURE
       String  left("abc");
       String  right("ab");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(left   == "abc");
        assert(right  == "ab");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("a");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(left   == "");
        assert(right  == "a");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("a");
        String  right("a");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(left   == "a");
        assert(right  == "a");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("a");
        String  right;

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(left   == "a");
        assert(right  == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); // 300 x's (over capacity)

      String  right;

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(left   == "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        assert(right  == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left = 'a'; 
        String  right("a");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(right  == "a");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left = 'a'; 
        String  right;

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(right  == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left = 'a'; 
        String  right("abc");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(right  == "abc");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left[] = "abc"; 
        String  right("a");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(right  == "a");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left[] = "abc"; 
        String  right("abcd");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(right  == "abcd");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left[] = "abcd"; 
        String  right("abcd");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(right  == "abcd");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left[] = ""; 
        String  right("abcd");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(right  == "abcd");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left[] = "abc"; 
        String  right;

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(right  == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left;
        String  right;

        // TEST
        bool result = (left > right);

        // VERIFY
        assert(result == false);
        assert(left   == "");
        assert(right  == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("a");

        // TEST
        bool result = (left > right);

        // VERIFY
        assert(result == false);
        assert(left   == "");
        assert(right  == "a");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("a");
        String  right("a");

        // TEST
        bool result = (left > right);

        // VERIFY
        assert(result == false);
        assert(left   == "a");
        assert(right  == "a");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("abc");
        String  right("a");

        // TEST
        bool result = (left > right);

        // VERIFY
        assert(result == true);
        assert(left   == "abc");
        assert(right  == "a");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("a");
        String  right("abc");

        // TEST
        bool result = (left > right);

        // VERIFY
        assert(result == false);
        assert(left   == "a");
        assert(right  == "abc");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right;

        // TEST
        bool result = (left >= right);

        // VERIFY
        assert(result == true);
        assert(left   == "");
        assert(right  == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right;

        // TEST
        bool result = (left <= right);

        // VERIFY
        assert(result == true);
        assert(left   == "");
        assert(right  == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("abc");
        String  right("a");

        // TEST
        bool result = (left >= right);

        // VERIFY
        assert(result == true);
        assert(left   == "abc");
        assert(right  == "a");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("");
        String  right("a");

        // TEST
        bool result = (left >= right);

        // VERIFY
        assert(result == false);
        assert(left   == "");
        assert(right  == "a");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("a");

        // TEST
        bool result = (left <= right);

        // VERIFY
        assert(result == true);
        assert(left   == "");
        assert(right  == "a");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      String  left("a");
        String  right;

        // TEST
        bool result = (left <= right);

        // VERIFY
        assert(result == false);
        assert(left   == "a");
        assert(right  == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right;

        // TEST
        bool result = (left != right);

        // VERIFY
        assert(result == false);
        assert(left   == "");
        assert(right  == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("a");

        // TEST
        bool result = (left != right);

        // VERIFY
        assert(result == true);
        assert(left   == "");
        assert(right  == "a");
    }
    std::cout << "Done testing inequalities." << std::endl;
}

