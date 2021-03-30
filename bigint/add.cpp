//==============================================================================
// Basics for openning a file for milestone 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
  bigint bi1, bi2;
  std::ifstream in("data1-1.txt");    // Define stream for input
  if(!in) {                           // Make sure it opened correctly.
    std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
    exit(1);
  }
   
  while (in >> bi1 && in >> bi2) {
    std::cout << "  " << bi1 << std::endl;
    std::cout << std::endl;
    std::cout << "+ " << bi2 << std::endl;
    std::cout << std::endl;
    std::cout << "= " << (bi1 + bi2) << std::endl;  
    std::cout << std::endl;
    std::cout << "---------------------------" <<  std::endl;
  }

  in.close();
  return 0;
}

