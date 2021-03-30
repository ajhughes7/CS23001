//==============================================================================
//

#include <iostream>
#include "bigint.hpp"

int main() {
  bigint b(100); 
  std::cout << (!b) << std::endl;
  // prints 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
  // (ends with 24 zeros)

  // Mathematical determination: 
  // Table printed of all factorials 1-100. Shows that zero is added 
  // to end every 5 values and an extra zero is added on top of that every 50. 
  // 20 zeros + 2 zeros + 2 zeros = 24 zero

  for (int i = 1; i <= 100; ++i) { 
    bigint b1(i);
    std::cout << i << ": " << (!b1) << std::endl;
  }
 return 0;  
}

