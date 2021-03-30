/**
 * Andrew Hughes
 * Programming Project 1: bigint Milestone 1
 * CS 23001
 */

#include <iostream>

const static int CAPACITY = 400;

class bigint {
public:
  bigint();
  bigint(int);
  bigint(const char []);
  void debugPrint(std::ostream&) const;
  int& operator[] (int index) { return intArray[index]; }; // returns i'th digit where i is the 10^ith position
  bigint timesDigit(int) const;
  bigint times10(int) const; 
  bigint operator!();

  friend std::ostream& operator<<(std::ostream&, const bigint&);
  friend bool operator==(const bigint&, const bigint&);
  friend bool operator==(const bigint&, int);
  friend std::istream& operator>>(std::istream&, bigint&);
  friend bigint operator+(bigint&, bigint&); 
  friend bigint operator*(bigint&, bigint&); 
private:
  int intArray[CAPACITY]={}; // initializes all elements to zero 
  int smallInt;
};
