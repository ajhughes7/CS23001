#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
            Date();
            Date(String s);
    friend  std::ostream& operator<<(std::ostream& out, const Date& d);
private:
    String  month;
    int     day, year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
            Time();
            Time(String s);
  friend  std::ostream& operator<<(std::ostream& out, const Time& t);
  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
            LogEntry();
            LogEntry(String s);
            void init();
            String getHost() const {return host;};
            Date getDate() const {return date;};
            Time getTime() const {return time;};
            String getRequest() const {return request;};
            String getStatus() const {return status;};
            int getNumberOfBytes() const {return number_of_bytes;};
            friend  std::ostream& operator<<(std::ostream&, const LogEntry&);    
private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::ifstream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);

#endif

