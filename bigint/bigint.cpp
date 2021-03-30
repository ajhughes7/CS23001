/**
 * Andrew Hughes
 * Programming Project 1: bigint Milestone 1
 * CS 23001
 */

#include <iostream>
#include <cstring>
#include "bigint.hpp"

bigint::bigint() {
  // bigint initialized to 0 upon declaration
  smallInt = 0; 
}

// digits distributed into intArray
bigint::bigint(int x) {
  smallInt = x;
  for (int i=0; i < CAPACITY; ++i) {
    int digit = x % 10;
    intArray[i] = digit;
    x /= 10;
    if (x == 0)
      break;
  }
}

// chars distributed into int array
bigint::bigint(const char ca[]) {
  int caLength = strlen(ca);
  // std::cout << ca << " " << caLength << std::endl; 
  for (int i=0; i < CAPACITY; ++i) {
    int caIndex = caLength - i - 1;
    intArray[i]=ca[caIndex] - '0'; // convert ASCII to int 
    if (caIndex == 0)
      break;
  }
}

// intArray output with "|" between digits for debugging
void bigint::debugPrint(std::ostream& os) const {
  for (int i = CAPACITY-1; i >= 0; --i)
    os << intArray[i]<< "|";
  os << std::endl;
}

// output bigint given os ostream
std::ostream& operator<<(std::ostream& os, const bigint& bi) {
  bool leading = true; 
  int digitCount = 0; 
  for (int i = CAPACITY-1; i >= 0; --i) {
    int element = bi.intArray[i];
    if (element == 0 && leading)
      continue;
    leading = false;
    os << element;
    if (++digitCount % 80 == 0)
      os << std::endl;
  }
  if (leading)
    os << 0;
  return os;
}

// returns true iff lhs bigint equals rhs int
bool operator==(const bigint& lhs, int rhs) {
  return (lhs == bigint(rhs));
}

// returns true iff lhs bigint equals rhs bigint
bool operator==(const bigint& lhs, const bigint& rhs) {
  for (int i = 0; i< CAPACITY; ++i){
    if (lhs.intArray[i] != rhs.intArray[i])
      return false;
  }
  return true;  
}

// reads in char digits 0-9 and places them in intArray via ASCII  
std::istream& operator>>(std::istream& is, bigint& bi) {
  char userDigit;
  int i = 0;
  char charArray[CAPACITY];
  do {
    is >> userDigit;
    charArray[i++] = userDigit;
  } while (userDigit != ';' && is.peek() != EOF);
  int numDigits = --i;
  while (--i >= 0)
    bi.intArray[numDigits - i - 1] = charArray[i] -'0'; // convert ASCII to int 
  // zero out leading columns in case dirty
  for (i = numDigits; i < CAPACITY; ++i)
    bi.intArray[i] = 0;
  return is;
}

// adds two bigints together through long addition and carrying method
bigint operator+ (bigint& l, bigint& r) {
  bigint total; 
  for (int i = 0, carry = 0; i < CAPACITY; ++i) {
    int columnSum = l[i] + r[i] + carry;
    carry = columnSum / 10;
    total[i] = columnSum % 10;
  }
  return total;
}

// multiplies a bigint with a single digit number
bigint bigint::timesDigit(int num) const {
  bigint result;  
  if (num >= 0 && num <= 9) {
    for (int i = 0, carry = 0; i < CAPACITY; ++i) {
      int columnProduct = intArray[i] * num + carry;
      carry = columnProduct / 10;
      result[i] = columnProduct % 10;
    }
  } else 
    std::cout << "ERROR: num not single digit: " <<  num << std::endl;
  return result;
}

// shifts bigint num digits to the left and fills in zeros
bigint bigint::times10(int num) const {
  bigint result; 
  if (num >= 0) {
    for (int i = 0; i < CAPACITY; ++i) {
      result[i + num] = intArray[i];
    }
  } else 
    std::cout << "ERROR: num is less than zero" << std::endl;
  return result; 
}

// multiplies two bigints 
bigint operator* (bigint& l, bigint& r) {
  bigint product = 0; 
  for (int i = 0; i < CAPACITY; ++i) {
    bigint temp =  r.timesDigit(l[i]);
    bigint tempTimes10 = temp.times10(i);
    product = product + tempTimes10; 
  }
  return product;
} 

/* bigint bigint::operator!() {
  bigint b = *this; 
  std::cout << b << std::endl;
  bigint bMinusOne = bigint(-1);
  if (b == 0 || b == 1)
    return 1;
  else {
    bigint bMinusOneFactorial = !(b + bMinusOne);
    return b * bMinusOneFactorial;
  }
  }
*/

bigint bigint::operator!() {
  bigint b = *this; 
  if (smallInt == 0 || smallInt == 1)
    return bigint(1);
  else {
    bigint bMinusOneFactorial = !(bigint(smallInt - 1));
    return b * bMinusOneFactorial;
  }
}
