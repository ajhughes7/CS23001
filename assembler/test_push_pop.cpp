//  Stack class test program
//
//  Tests: push pop 
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
        stack<int>  x;

        // TEST
        x.push(2);

        // VERIFY
        assert(!x.empty());
     }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int>  x;
	
        // TEST
        x.push(2);
	int result = x.pop();
	
        // VERIFY
        assert(x.empty());
        assert(result == 2);
     }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int>  x;
	
        // TEST
        x.push(2);
	x.push(3);
	int result = x.pop();
	
        // VERIFY
        assert(!x.empty());
        assert(result == 3);
     }
     {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int>  x;
	
        // TEST
        x.push(2);
       	int result = x.pop();
	assert(result == 2);
        assert(x.empty());
	  
	x.push(4);
       	result = x.pop();
	assert(result == 4);
        assert(x.empty());
     }
     {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int>  x;
	
        // TEST
        x.push(2);
	x.push(4);
	x.push(6);
	assert(x.pop() == 6);
        assert(!x.empty());
	assert(x.pop() == 4);
	assert(!x.empty());
	assert(x.pop() == 2);
	assert(x.empty());

 }


     // String tests 



    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>  x;

        // TEST
        x.push(String("2"));

        // VERIFY
        assert(!x.empty());
     }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>  x;
	
        // TEST
        x.push(String("2"));
	String result = x.pop();
	
        // VERIFY
        assert(x.empty());
        assert(result == String("2"));
     }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>  x;
	
        // TEST
        x.push(String("2"));
	x.push(String("4"));
	String result = x.pop();
	
        // VERIFY
        assert(!x.empty());
        assert(result == String("4"));
     }
     {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>  x;
	
        // TEST
        x.push(String("2"));
       	String result = x.pop();
	assert(result == String("2"));
        assert(x.empty());
	  
	x.push(String("4"));
       	result = x.pop();
	assert(result == String("4"));
        assert(x.empty());
     }
     {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>  x;
	
        // TEST
        x.push(String("2"));
	x.push(String("4"));
	x.push(String("6"));
	assert(x.pop() == String("6"));
        assert(!x.empty());
	assert(x.pop() == String("4"));
	assert(!x.empty());
	assert(x.pop() == String("2"));
	assert(x.empty());

 }

     //top function

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int>  x;

        // TEST
        x.push(2);
	
        // VERIFY
        assert(x.top() == 2);
	assert(!x.empty());
     }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>  x;

        // TEST
        x.push(String("2"));
	x.push(String("4"));
	
        // VERIFY
        assert(x.top() == String("4"));
     }


    std::cout << "Done testing push pop." << std::endl;
}

