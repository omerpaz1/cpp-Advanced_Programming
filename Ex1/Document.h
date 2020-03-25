#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Document{

public:
    std::vector<string> myDocument;
    vector<string>::iterator tempiter;
    string Slash = "";

    vector<string>::iterator itForSlesh; // for / function "/"
    int LineNumber;
    Document();
    vector<string>::iterator getLine(int);
    void readLine(); // a
    void insertBefore(); // i
    void swapWord(); //c
    void removeWord(); // d
    void changeWord(string); // s/old/new
    void printcorrent(); // p
    void searchFowrad(string); // '/text'
    void searchBackwards(string); // '?text'
    void printLineNumberAndValue(); // n
    void backShlash(); // '/'
    

private: 
    void update();
    void readLines();
    int correntline = 0;


    


};
