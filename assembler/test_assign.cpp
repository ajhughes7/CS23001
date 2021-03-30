//  Stack class test program
//
//  Tests: assign and swap
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
        stack<String>  x;
        stack<String>  y;

        // TEST
	x.push(String("hello"));
	x.push(String("hi"));
	x.push(String("hola"));

	y.push(String("goodbye"));
	y.push(String("bye"));
        y.push(String("adios"));

	x.swap(y);

        // VERIFY
        assert(y.top() == String("hola"));
	assert(x.top() == String("adios"));
     }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>  x;
        stack<String>  y;

        // TEST
	x.push(String("hello"));
	x.push(String("hi"));
	x.push(String("hola"));

	y.push(String("goodbye"));
	y.push(String("bye"));
        y.push(String("adios"));

	x = y;

        // VERIFY
        assert(y.top() == String("adios"));
	assert(x.top() == String("adios"));
	assert(y.pop() == String("adios"));
	assert(x.pop() == String("adios"));
	assert(y.pop() == String("bye"));
	assert(x.pop() == String("bye"));
	assert(y.pop() == String("goodbye"));
	assert(x.pop() == String("goodbye"));
	assert(y.empty());
	assert(x.empty());

	y.push(String("a"));
	x.push(String("b"));

        assert(y.top() == String("a"));
	assert(x.top() == String("b"));

     }




    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing assign and swap." << std::endl;
}

