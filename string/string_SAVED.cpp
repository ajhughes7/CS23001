/**
 * Andrew Hughes
 * Programming Project 2: String Project
 * CS 23001
 */

#include <iostream>
#include <cstring>
#include "string.hpp"
#include <cassert>
#include <vector>

String::String() {
  // string initialized to empty string with null terminator
  stringSize = 1;
  str = new char [stringSize]; 
  str[0] = 0;
}

String::String(int cap) {
  stringSize = cap + 1;
  str = new char [stringSize]; 
  str[0] = 0;
}

String::String(char c) {
  stringSize = 2;
  str = new char [stringSize]; 
  str[0] = c; 
  str[1] = 0; 
}

String::String(const char ca[]) {
  stringSize = 0;
  while (ca[stringSize++] != 0)
    ;
  str = new char [stringSize];
  int i = 0;
  while (ca[i] != 0) {
    str[i] = ca[i]; 
    ++i; 
  }
  str[i] = 0;
}

String::String(int cap, const char ca[]) {
  stringSize = cap + 1;
  str = new char [stringSize];
  int i = 0;
  while (ca[i] != 0) {
    str[i] = ca[i]; 
    ++i; 
  }
  str[i] = 0;
}

String::~String() {
  delete [] str;
}

bool operator==(const char charStr[], const String& s) {
  return String(charStr) == s;
}  

bool operator==(char c, const String& s) {
  return String(c) == s;
}  

bool String::operator==(const String& s) const {
  for (int i = 0; i < stringSize; ++i){
    if (s.str[i] != this->str[i])
      return false;
    if (s.str[i] == 0)
      break;
  }
  return true;  
}

int String::length() const {
  int result = 0; 
  while (str[result] != 0) ++result; 
  return result; 
}

int String::capacity() const {
  return stringSize - 1; // -1 for string termination char. 
}

//Accessor/Modifier
char& String::operator[](int i) {
  assert( (i >= 0) && (i <length()) ); 
  return str[i];
}

//Accessor
char String::operator[](int i) const {
  assert( (i >= 0) && (i <length()) ); 
  return str[i];
}


void String::resetCapacity(int ncap) {
  char *temp = new char [ncap];
  int i = 0;
  while (str[i] != 0) {
    temp[i] = str[i];
    ++i;
  }
  temp[i] = 0;
  delete [] str;
  str = temp;
}

String& String::operator+=(const String& rhs) {
  int i = 0; 
  int offset = length();
  resetCapacity(length() + rhs.length());
  while (rhs.str[i] != 0) {
    str[offset + i] = rhs.str[i]; 
    ++i; 
  }
  stringSize = rhs.length() + offset + 1;
  str[offset + i] = 0;
  return *this;
} 

String String::operator+(const String& rhs) const {
  String result(str); 
  int offset = length();
  int i = 0; 
  result.resetCapacity(length() + rhs.length());
  while (rhs.str[i] != 0) {
    result.str[offset + i] = rhs.str[i]; 
    ++i; 
  }
  result.str[offset + i] = 0;
  result.stringSize = offset + i + 1;
  return result;
}

String operator+(const char lhs[], const String& rhs) {
  return String(lhs) + rhs; 
}

String operator+(char lhs, const String& rhs) {
  return String(lhs) + rhs; 
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
  out << rhs.str;
  return out;
}

bool String::operator<(const String& rhs) const {
  int i = 0; 
  while ((str[i] != 0 ) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) 
    ++i;
  return str[i] < rhs.str[i];
} 

bool operator<(const char lhs[], const String& rhs) {
  return String(lhs) < rhs; 
}

bool operator<(char lhs, const String& rhs) {
  return String(lhs) < rhs; 
}

bool operator<=(const String& lhs, const String& rhs) {
  return (lhs < rhs) || (lhs == rhs);
} 

bool operator>(const String& lhs, const String& rhs) {
  return rhs < lhs; 
}

bool operator>=(const String& lhs, const String& rhs) {
  return (lhs > rhs) || (lhs == rhs);
}

bool operator!=(const String& lhs, const String& rhs) {
  return !(lhs == rhs);
}

int String::findch(int pos, char ch) const{
  for (int i = pos; i < stringSize; ++i) {
    if (str[i] == ch)
      return i;
    if (str[i] == 0)
      break;
  }
  return -1;
}

String& String::operator=(String s) {
  stringSize = 0;
  while (s.str[stringSize++] != 0)
    ;
  str = new char [stringSize];
  for (int i = 0; i < stringSize; ++i)
    str[i] = s.str[i];
  return *this;
} 

int String::toInt() {
  return atoi(str);
}

String::String(const String& s) {
  //stringSize = 0;
  //while (s.str[stringSize++] != 0)
  // ;
  stringSize = s.stringSize;
  str = new char [stringSize];
  for (int i = 0; i < stringSize; ++i)
    str[i] = s.str[i];
}

String String::substr(int start, int end) const {
  //  assert ( (start >= 0) && (start < length()) ); 
  // assert ( (end >= 0) && (end < length()) );
  // assert (start <= end);
  if (start > end)
    return String();
  char charArray[stringSize];  
  for (int i = start; i <= end; ++i) {
    charArray[i - start] = str[i];
  }
  charArray[end - start + 1] = 0;
  return String(charArray);
}

int String::findstr(int pos, const String& s) const {
  assert (s.length() > 0);
  
  for (int i = pos; i < stringSize - s.length(); ++i) { 
    if (substr(i, i + s.length() -1) == s)
      return i;
    if (str[i] == 0)
      break;
  }
  return -1;
} 

void String::swap(String& s) {
  String temp = s;
  s.str = str;
  s.stringSize = stringSize;
  str = temp.str;
  //std::cout << "" << std::endl; 
  stringSize = temp.stringSize;
  temp.str = 0;
}

const int MAX_INPUT = 1024;

std::istream& operator>>(std::istream& in, String& rhs) {
  char buf[MAX_INPUT];
  if (!in.eof())
    in >> buf;
  else
    buf[0] = 0;
  rhs = String(buf);
  return in;  
}


std::vector<String> String::split(char splitChar) const {
  std::vector<String> v;
  for (int i = 0, start = 0; i < stringSize; ++i) {
    if (str[i] == splitChar || i == stringSize - 1) {
      v.push_back(substr(start, i - 1)); 
      start = i + 1;
    }  
  }
  return v;
}


