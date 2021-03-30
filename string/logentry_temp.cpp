LogEntry::LogEntry(String s) {
  std::vector<String> vec = s.split(' ');
  if (vec.size() == 10 && false) {
    std::cout << "1" << std::endl;
    host = String(vec[0]);
    std::cout << "2" << std::endl;
    // [18/Sep/2002:12:05:25 -0400] 
    date = Date(vec[3].substr(1, 11));
    //date = Date();
    std::cout << "3" << std::endl;
    time = Time(vec[3].substr(13, 20));  
    //time = Time();  
    std::cout << "4" << std::endl;
    
    
    //    request = vec[5].substr(1, vec[5].length() - 1);
    /*    request = vec[5];
    std::cout << "4.1" << std::endl;
    request += " ";
    std::cout << "4.2" << std::endl;
    request += vec[6];
    std::cout << "4.3" << std::endl;
    request += " ";
    std::cout << "4.4" << std::endl;
    request += vec[7];
    */
    std::cout << "5" << std::endl;
    status = vec[8];
    std::cout << "vec[9]= " << vec[9] <<std::endl;
       
    if (vec[9] == '-')
      number_of_bytes = 0;   
    else
      number_of_bytes = vec[9].toInt();
    std::cout << "6" << std::endl;
  } else 
    init();
}
