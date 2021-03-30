//  Stack class test program
//
//  Tests: postfix to assembly 
//

#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "string.hpp"
#include "utilities.hpp"

//===========================================================================
int main ()
{
  {
    String assembly = postfix_to_assembly( "A B +");
    std::cout << "assembly: " << std::endl << assembly << std::endl;
    assert(assembly == "LD A\nAD B\nST TMP1\n");
  }
  {
    String assembly = postfix_to_assembly( "AX BX +");
    std::cout << "assembly: " << std::endl << assembly << std::endl;
    assert(assembly == "LD AX\nAD BX\nST TMP1\n");
  }
  {
    String assembly = postfix_to_assembly( "AX BX -");
    std::cout << "assembly: " << std::endl << assembly << std::endl;
    assert(assembly == "LD AX\nSB BX\nST TMP1\n");
  }
  {
    String assembly = postfix_to_assembly( "AX BX *");
    std::cout << "assembly: " << std::endl << assembly << std::endl;
    assert(assembly == "LD AX\nMU BX\nST TMP1\n");
  }
  {
    String assembly = postfix_to_assembly( "AX BX /");
    std::cout << "assembly: " << std::endl << assembly << std::endl;
    assert(assembly == "LD AX\nDV BX\nST TMP1\n");
  }
  {
    String assembly = postfix_to_assembly( "A B C * + D E - /");
    std::cout << "assembly: " << std::endl << assembly << std::endl;
    String exp1 = "LD B\nMU C\nST TMP1\n";
    String exp2 = "LD A\nAD TMP1\nST TMP2\n";
    String exp3 = "LD D\nSB E\nST TMP3\n";
    String exp4 = "LD TMP2\nDV TMP3\nST TMP4\n";
    assert(assembly == exp1 + exp2 + exp3 + exp4);
  }
  
  std::cout << "Done testing postfix to assembly." << std::endl;
  
}
