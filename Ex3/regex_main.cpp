// C++ program to show the working 
// of regex_replace 
#include <bits/stdc++.h> 
using namespace std; 
QueryResult NQuery::eval(const TextQuery &text) const{
  QueryResult QR = AndQuery::eval(text);

  auto ret_lines = std::make_shared<std::set<line_no>>();//where we return our lines
  auto iter = QR.begin();


  for (; iter != QR.end(); ++iter){
  string currLine = QR.get_file()->at(*iter);
        
        

    
    // * insert the line to the return line */
     ret_lines->insert(*iter);
     
  }
  return QueryResult(rep(), ret_lines, QR.get_file());

}