#ifndef CS2_UTILITIES_HPP_
#define CS2_UTILITIES_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: utilities.hpp
//
// Programmer: Andrew Hughes
// Updated:    11/2019

#include "../string/string.hpp" 

String infix_to_postfix(char const *expr);
String postfix_to_assembly(String expr);

#endif
