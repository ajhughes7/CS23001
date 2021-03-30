// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "string.hpp" 
#include "logentry.hpp"

Time::Time(String s) {
  std::vector<String> vec = s.split(':');
  hour = vec[0].toInt(); 
  minute = vec[1].toInt(); 
  second = vec[2].toInt(); 
}

Time::Time() {
  hour = 0;
  minute = 0;
  second = 0;
}

Date::Date() {
  day = 0;
  month = "";
  year = 0;
}

Date::Date(String s) {
  std::vector<String> vec = s.split('/');
  day = vec[0].toInt(); 
  month = vec[1]; 
  year = vec[2].toInt(); 
}

std::ostream& operator<<(std::ostream& out, const Date& d) {
  out << std::setw(2) << std::setfill('0') << d.day << "/" 
      << d.month << "/" 
      << std::setw(4) << std::setfill('0') << d.year; 
    return out;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
  out << std::setw(2) << std::setfill('0') << t.hour << ":" 
      << std::setw(2) << std::setfill('0') << t.minute << ":"  
      << std::setw(2) << std::setfill('0') << t.second; 
    return out;
}

LogEntry::LogEntry() {
  init();
}

void LogEntry::init() {
  host = String();
  date = Date();
  time = Time();
  request = String();
  status = String();
  number_of_bytes = 0;
}

LogEntry::LogEntry(String s) {
  std::vector<String> vec = s.split(' ');
  // std::vector<String> vec2 = s.split('"');
  init();
  if (vec.size() == 10) {
    host = vec[0];
    date = Date(vec[3].substr(1, 11));
    time = Time(vec[3].substr(13, 20));

    //131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] "GET /~darci/ HTTP/1.0" 200 5625
    
    request = vec[5].substr(1, vec[5].length()) 
            + ' ' + vec[6] 
	    + ' ' + vec[7].substr(0, vec[7].length() - 2);
    //    request = vec2[1];
    status = vec[8];
    if (vec[9] == '-')
      number_of_bytes = 0;   
    else
      number_of_bytes = vec[9].toInt();
  }
}

const int BUF_SIZE = 1024;
std::vector<LogEntry> parse(std::ifstream& in) {
  std::vector<LogEntry> result;
  char buf[BUF_SIZE];
  
  while (!in.eof()) {       
    in.getline(buf, BUF_SIZE);
    String line = String(buf);
    //std::cout << "line = " << line << std::endl;
    if (line != "") 
      result.push_back(LogEntry(line));    
  }
  return result;
}
  
void output_all(std::ostream& out, const std::vector<LogEntry> &vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    out << vec[i] << std::endl;
  }
}

std::ostream& operator<<(std::ostream& out, const LogEntry& le) {
  out << le.getHost() << " [" 
      << le.getDate() << " " 
      << le.getTime() << "] \""  
      << le.getRequest() << "\" " 
      << le.getStatus() << " " 
      << le.getNumberOfBytes();
  return out;
}

void by_host(std::ostream& out, const std::vector<LogEntry>& vec) {
  for (size_t i = 0; i < vec.size(); i++)
    out << vec[i].getHost() << std::endl;
}

int byte_count(const std::vector<LogEntry>& vec) {
  int totalBytes = 0;
  for (size_t i = 0; i < vec.size(); i++)
    totalBytes += vec[i].getNumberOfBytes();
  return totalBytes;
}
