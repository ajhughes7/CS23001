// File:        postfix.cpp
//       
// Version:     1.0
// Date:        Fall 2019
// Author:      
//
// Description: Main body for postfix

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "utilities.hpp"
#include "string.hpp" 

void output_usage_and_exit(const char cmd[]);

int main(int argc, char *argv[]) {

    // Error if there are not 3 things on the command line
    if (argc != 3 && argc != 2) { output_usage_and_exit(argv[0]); }

    // Open input file, quit if open fails
    std::ifstream in(argv[1]);
    if (!in) { std::cerr << "Couldn't open " << argv[1] << std::endl; exit(2)
; }
    // Based on: https://stackoverflow.com/questions/428630/assigning-cout-to-a-variable-name

    std::ofstream realOutFile;

    if(argc == 3)
      realOutFile.open(argv[2], std::ios::out);

    std::ostream & outFile = (argc == 3 ? realOutFile : std::cout);

    int LINE_SIZE = 1024;
    char line[LINE_SIZE];
    
    do {
      in.getline(line, LINE_SIZE);
      if(line[0] == 0)
	continue;
      outFile << "Infix Expression: " << line << std::endl;
      String postfix = infix_to_postfix(line);
      outFile << "Postfix Expression: " << postfix << std::endl;
    } while (!in.eof());
    in.close();
    return 0;
}

void output_usage_and_exit(const char cmd[]) {
  // Output usage message
  std::cerr << "Usage: " << cmd << " input [output]" << std::endl;
  // Exit with error
  exit(1);
}
