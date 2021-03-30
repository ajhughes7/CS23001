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
        bi = bi.times10(1);

        // Verify
        assert(bi == 30); 
	bi = bi.times10(2);
	assert(bi == 3000);     
	bi = bi.times10(4);
	assert(bi == 30000000);     
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(9876);

        // Test 
        bi = bi.times10(1);

        // Verify
        assert(bi == 98760); 
	bi = bi.times10(3);
	assert(bi == 98760000);     
    }
    {
        //------------------------------------------------------
        // Setup fixture
        // 20 zeros
        bigint bi("98760000000000000000000000000000000000000000");

        // Test 
        bi = bi.times10(10);

        // Verify
        assert(bi == "987600000000000000000000000000000000000000000000000000"); 
    }
    std::cout << "Done testing times_10" << std::endl;
}

