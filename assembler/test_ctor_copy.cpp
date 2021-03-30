//  Stack class test program
//
//  Tests: copy constructor
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

        stack<String>  y = x; //invokes copy ctor
	
	assert(x.top() == "hi");
	assert(y.top() == "hi");
	assert(x.pop() == "hi");
	assert(y.pop() == "hi");	
	assert(x.pop() == "hello");
	assert(y.pop() == "hello");
	x.push(String("hola"));
	assert(x.top() == "hola");
	assert(y.empty());
     
    }
    std::cout << "Done testing copy constructor." << std::endl;
}

