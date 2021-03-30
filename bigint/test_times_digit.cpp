// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(3);

        // Verify
        assert(bi == 9); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(4);

        // Test 
        bi = bi.timesDigit(3);

        // Verify
        assert(bi == 12); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.timesDigit(3);

        // Verify
        assert(bi == 0); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test 
        bi = bi.timesDigit(3);

        // Verify
        assert(bi == 3); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(9);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 81); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(30);

        // Test 
        bi = bi.timesDigit(3);

        // Verify
        assert(bi == 90); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(300);

        // Test 
        bi = bi.timesDigit(3);

        // Verify
        assert(bi == 900); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(100);

        // Test 
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == 500); 
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	
	bigint bi2("3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333"); 


        // Test 
        bi = bi.timesDigit(3);
	

        // Verify
        assert(bi == bi2);
    }
    std::cout << "Done testing bigint * digit" << std::endl;
}