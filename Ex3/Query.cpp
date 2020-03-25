#include "Query.h"
#include "TextQuery.h"
#include <memory>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <regex>
using namespace std;
////////////////////////////////////////////////////////////////////////////////
std::shared_ptr<QueryBase> QueryBase::factory(const string& s)
{     

     regex regexAND("^\\s*([\\w']+)\\s+(AND)\\s+([\\w']+)\\s*$");
     regex regexOR("^\\s*([\\w']+)\\s+(OR)\\s+([\\w']+)\\s*$");
     regex regexN("^\\s*([\\w']+)\\s+(\\d+)\\s+([\\w']+)\\s*$");
     regex regexNOT("^\\s*NOT\\s+([\\w']+)\\s*$");
     regex regexW("^\\s*([\\w']+)\\s*$");


    istringstream myStream(s);
		vector<string> result((istream_iterator<string>(myStream)),istream_iterator<string>());

   if(regex_match(s,regexW)) return std::shared_ptr<QueryBase>(new WordQuery(result[0]));
   if(regex_match(s,regexNOT)) return std::shared_ptr<QueryBase>(new NotQuery(result[1]));
   else if(regex_match(s,regexAND)) return std::shared_ptr<QueryBase>(new AndQuery(result[0],result[2]));
   else if(regex_match(s,regexOR)) return std::shared_ptr<QueryBase>(new OrQuery(result[0],result[2]));
   else if(regex_match(s,regexN)) return std::shared_ptr<QueryBase>(new NQuery(result[0],result[2],stoi(result[1])));
   else throw invalid_argument ("Unrecognized search");

}
////////////////////////////////////////////////////////////////////////////////
QueryResult NotQuery::eval(const TextQuery &text) const
{
  QueryResult result = text.query(query_word);
  auto ret_lines = std::make_shared<std::set<line_no>>();
  auto beg = result.begin(), end = result.end();
  auto sz = result.get_file()->size();
  
  for (size_t n = 0; n != sz; ++n)
  {
    if (beg==end || *beg != n)
		ret_lines->insert(n);
    else if (beg != end)
		++beg;
  }
  return QueryResult(rep(), ret_lines, result.get_file());
    
}

QueryResult AndQuery::eval (const TextQuery& text) const
{
  QueryResult left_result = text.query(left_query);
  QueryResult right_result = text.query(right_query);
  
  auto ret_lines = std::make_shared<std::set<line_no>>();
  std::set_intersection(left_result.begin(), left_result.end(),
      right_result.begin(), right_result.end(), 
      std::inserter(*ret_lines, ret_lines->begin()));

  return QueryResult(rep(), ret_lines, left_result.get_file());
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
  QueryResult left_result = text.query(left_query);
  QueryResult right_result = text.query(right_query);
  
  auto ret_lines = 
      std::make_shared<std::set<line_no>>(left_result.begin(), left_result.end());

  ret_lines->insert(right_result.begin(), right_result.end());

  return QueryResult(rep(), ret_lines, left_result.get_file());
}
/////////////////////////////////////////////////////////
QueryResult NQuery::eval(const TextQuery &text) const{
  QueryResult QR = AndQuery::eval(text);

  regex firstWord(left_query);
  regex secondWord(right_query);
  auto ret_lines = std::make_shared<std::set<line_no>>();//where we return our lines
  auto iter = QR.begin();

  vector<string> myvec;

  for (; iter != QR.end(); ++iter){
  string currLine = QR.get_file()->at(*iter);
  std::regex rx("(\\w+)(\\s)*");

  
   auto words_begin = std::sregex_iterator(currLine.begin(), currLine.end(), rx);
   auto words_end = std::sregex_iterator();


     for(auto i = words_begin; i != words_end; ++i)
   {  
     auto match = *i;
     myvec.push_back(match[1]);
   }
    auto firstW = std::find (myvec.begin(), myvec.end(), left_query); 
    auto SecW = std::find (myvec.begin(), myvec.end(), right_query); 
    int count = distance(firstW,SecW);
    cout << count-1 << "dist " << dist << endl;
    if(count < 0 ){
     count = distance(SecW,firstW);
    }

   if(count-1 <= dist){
     ret_lines->insert(*iter);
     
   }

  }
  return QueryResult(rep(), ret_lines, QR.get_file());

}



/////////////////////////////////////////////////////////