#include "Document.h"
#include <iostream>
using namespace std;




Document::Document() {

   Slash = "";

};

vector<string>::iterator Document::getLine(int i){
        LineNumber=i;

    std::vector<string>::iterator it = myDocument.begin() + i-1;
    tempiter = it;
    cout << *it << endl;
    return it;
}

void Document::printcorrent(){ // p
      if(LineNumber == 0){
        tempiter = myDocument.end()-1;  
        cout << *tempiter << endl;
      }else{
      tempiter = myDocument.begin()+LineNumber-1;
      cout << *tempiter << endl;
      }

}

void Document::printLineNumberAndValue(){
    cout << LineNumber << "\t" << *tempiter << endl;
}

void Document::readLine(){ // a
    bool text = true;
    std::string line = "";
    std::getline(std::cin, line);
    cout<< line;
    while(text){
            std::getline(std::cin, line);
            cout<< line <<endl;
            if(line != ""  && line.at(0) == '.'){
            text = false;
            }
        else {    
        tempiter=myDocument.begin()+LineNumber;
        LineNumber++;
        myDocument.insert(tempiter,line);
        }
   }


}

void Document::insertBefore(){ // i
    bool text = true;
    std::string line = "";
    std::getline(std::cin, line);
    cout<< line;
    while(text){
            std::getline(std::cin, line);
            cout<< line <<endl;
            if(line != ""  && line.at(0) == '.'){
            text = false;
        }
        else {
        tempiter=myDocument.begin()+LineNumber;
        LineNumber++;
        myDocument.insert(tempiter-1,line);
        }
   }
}

void Document::swapWord(){ // c
    removeWord();
    insertBefore();
   }
    

void Document::removeWord(){ //d 
    std::vector<string>::iterator it = tempiter;
      myDocument.erase (tempiter);
      tempiter = it;
}

void Document::changeWord(string s){ // s/old/new/"
    string oldString;
    string newString; 
    std::string delimiter = "/";
    string array[2];
    int i = 0;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    if(token != "s"){
    array[i] = token;
    i++;
    }
    s.erase(0, pos + delimiter.length());
} 
    oldString = array[0];
    newString = array[1];


    for(vector<string>::iterator it = myDocument.begin() ; it != myDocument.end() ; ++it){
        
        std::size_t found = (*it).find(oldString);
        if(found!=std::string::npos){
        (*it).replace(found,oldString.length(),newString);

        }
}
}


void Document::searchFowrad(string s){ // /text
        bool found=false;
        Slash = s;
        for(vector<string>::iterator it=tempiter; it != myDocument.end() ; it++){
                        
            if(((*it).find(Slash) != std::string::npos)){
                cout << *it << endl;
                itForSlesh = it;
                tempiter=it;
                update();
                found=true;
                break;
            }
        }
        if(!found){//if not found ->search again and again
            tempiter=myDocument.begin();
            searchFowrad(s);
        }
}

void Document::searchBackwards(string s){  // '?text'
        Slash = s;
        for(vector<string>::iterator it=tempiter; it != myDocument.begin()-1 ; it--){
                if(((*it).find(Slash) != std::string::npos)){
                cout << *it << endl;
                itForSlesh = it;
                tempiter=it;
                update();
                break;
            }
        }

}


void Document::backShlash(){
    tempiter++;
    searchFowrad(Slash);
}


void Document::update(){

   correntline = 1;
   for(vector<string>::iterator it=myDocument.begin(); it != tempiter ; it++){
    correntline++;
    
    }
    LineNumber = correntline;
}



