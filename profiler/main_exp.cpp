//File main1.cpp
#include <iostream>
           
int main() {  main1_cpp.count(__LINE__, "main"); 
  int i;
  i = 0; main1_cpp.count(__LINE__); 
  while (main1_cpp.count(__LINE__), i < 10) {    
    ++i;   
    std::cout << i;
  }
  std::cout << main1_cpp << std::endl;  
  return 0;
} 


