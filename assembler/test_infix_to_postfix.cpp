//  Stack class test program
//
//  Tests: infix to postfix 
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
    // valid input expressions single-char operands
    assert(infix_to_postfix("( A + B ) ;") == "A B +");
    assert(infix_to_postfix("( ( A + B ) * C ) ;") == "A B + C *");
    assert(infix_to_postfix("( ( A + B ) * C ) ;") == "A B + C *");
    assert(infix_to_postfix("( A + ( B * C ) ) ;") == "A B C * +");
    assert(infix_to_postfix("( A + ( B * C ) ) / ( D - E ) ) ;") == "A B C * + D E - /");
    assert(infix_to_postfix("( ( A + B ) * ( C + E ) ) ;") == "A B + C E + *");
    assert(infix_to_postfix("( A * ( B * ( ( ( C + A ) + B ) * C ) ) ) ;") == "A B C A + B + C * * *");
    assert(infix_to_postfix("( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J ) ;") == "H A B C + D * + F * G * E * * J +");

  }
  {
    // valid input expressions multi-char operands
    assert(infix_to_postfix("( AA + BB ) ;") == "AA BB +");
    assert(infix_to_postfix("( ( AAA + BBB ) * CCC ) ;") == "AAA BBB + CCC *");
    assert(infix_to_postfix("( ABCDEF + ( BBB * CCC ) ) ;") == "ABCDEF BBB CCC * +");
    assert(infix_to_postfix("( ( HHH * ( ( ( ( AAA + ( ( BBB + CC ) * Dd ) ) * F ) * G ) * E ) ) + J ) ;") == "HHH AAA BBB CC + Dd * + F * G * E * * J +");

  }
  {
    // invalid input expressions that still work
    assert(infix_to_postfix("( A + B )") == "A B +");
    assert(infix_to_postfix("(A+B)") == "A B +");
    assert(infix_to_postfix("( A + B );") == "A B +");
  }

  std::cout << "Done testing infix to postfix." << std::endl;

}

/*

( AX + ( B * C ) ) ;
( ( AX + ( B * CY ) ) / ( D - E ) ) ;
( ( A + B ) * ( C + E ) ) ;
( AX * ( BX * ( ( ( CY + AY ) + BY ) * CX ) ) ) ;
( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J ) ;

*/
