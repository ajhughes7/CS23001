//File main1.cpp
#include <iostream>
           
#include "profile.hpp"
profile main1_cpp("main1.cpp");
int main() {  main1_cpp.count(__LINE__,"main");  
  int i;
  i = 0;  main1_cpp.count(__LINE__); 
  while (  main1_cpp.count(__LINE__),i < 10) {    
    ++i;  main1_cpp.count(__LINE__);   
    std::cout << i;  main1_cpp.count(__LINE__);
  }
  std::cout << main1_cpp << std::endl;
  return 0;
} 



