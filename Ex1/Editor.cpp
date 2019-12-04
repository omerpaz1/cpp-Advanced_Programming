#include "Editor.h"
#include <iostream>
#include <string>
using namespace std;


void Editor::loop(){
    string s;

    cin >> s ;  
    while (s != "Q"){

        if(s == "p"){
            cout<< "p" <<endl;
            Document::printcorrent();
            loop();
        }
        else if (s == "n"){
            cout<< "n" <<endl; 
            Document::printLineNumberAndValue();
            loop();
        }
        else if (s == "%p"){
            cout<< "%p" <<endl;
            for(auto i : myDocument){
                cout << i << endl;
            }
            loop();
        }
        else if (s == "a"){
            cout<< "a" <<endl; 
            Document::readLine();
            loop();
        }

        else if (s == "i"){
            cout<< "i" <<endl; 
            Document::insertBefore();
            loop();
        }   
        else if (s == "c"){
            cout<< "c" <<endl; 
            Document::swapWord();
            loop();
        }
        else if (s == "d"){
            cout<< "d" <<endl;
            Document::removeWord();
            loop();
        }
        else if (s.at(0) == '/' && s.size() >1){
            cout<< s <<endl;
            string toSearch = s.substr(1); 
            Document::searchFowrad(toSearch);
            loop();
        }
        else if (s.at(0) == '/') {
            cout<< "/" <<endl;
            Document::backShlash();
            loop();
        }
        else if (s.at(0) =='?'){
            cout<< s <<endl;
            string toSearch = s.substr(1); 
            Document::searchBackwards(toSearch);
            loop();
        }
        else if (s.at(0) == 's' && s.at(1) == '/' && s.at(s.length()-1)=='/'){
            cout<< s <<endl;
            Document::changeWord(s);
            loop();
        }
        else if (s == "1"){
            cout<< "1" <<endl;
            LineNumber = 1;
            vector<string>::iterator it  = Document::getLine(1);
            tempiter = it;
            loop();
        }
        else if (s == "2"){
            cout<< "2" <<endl;
            LineNumber = 2;
            vector<string>::iterator it  = Document::getLine(2);
            tempiter = it;
            loop();
        }
        else if (s == "3"){
            cout<< "3" <<endl;
            LineNumber = 3;
            vector<string>::iterator it  = Document::getLine(3);
            tempiter = it;
            loop();        
        }   
        else if (s == "4"){
            cout<< "4" <<endl;
            LineNumber = 4;
            vector<string>::iterator it  = Document::getLine(4);
            tempiter = it;
            loop();        
        }   
        else if (s == "5"){
            cout<< "5" <<endl;
            LineNumber = 5;
            vector<string>::iterator it  = Document::getLine(5);
            tempiter = it;
            loop();        
        }           
        else if (s == "6"){
            cout<< "6" <<endl;
            LineNumber = 6;
            vector<string>::iterator it  = Document::getLine(6);
            tempiter = it;
            loop();        
        }   
        else if (s == "7"){
            cout<< "7" <<endl;
            LineNumber = 7;
            vector<string>::iterator it  = Document::getLine(7);
            tempiter = it;
            loop();        
        }    
        else if (s == "8"){
            cout<< s <<endl;
           LineNumber = 8;
            vector<string>::iterator it  = Document::getLine(8);
            tempiter = it;
            loop();        
        }  
        else if (s == "9"){
            cout<< s <<endl;
           LineNumber = 9;
            vector<string>::iterator it  = Document::getLine(9);
            tempiter = it;
            loop();        
        }  
        else{
            throw new exception;
        }
        
    }
    cout<< "Q" <<endl;
    exit(0);
}





