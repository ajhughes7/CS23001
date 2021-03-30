//  String class test program
//
//  Tests: logentry ctor
//

#include "string.hpp" 
#include "logentry.hpp"
#include <cassert>

int main() {
  {
    LogEntry le;
              
    assert(le.getHost() == "");
    assert(le.getNumberOfBytes() == 0);
  } 
  {
    LogEntry le("131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] \"GET /~darci/ HTTP/1.0\" 200 5625");
              
    assert(le.getHost() == "131.123.47.176");
    assert(le.getNumberOfBytes() == 5625);
  
  } 

  std::cout << "Done testing logentry ctor." << std::endl;
}

 
