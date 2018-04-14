//g++ prog2_2.cpp prog2_1.cpp -o prog2_2
#include <iostream>
#include <sstream> // take this string and consider it as a stream
#include <vector>  // arraylist
#include <fstream> // file stream
#include "prog2_1.hpp"
using namespace std;

  int main(int argc, char const *argv[]) {
    if(argc != 2) {
        return 0; // end it. you broke my stuff
        //dead
    }

    cout << "Assignment #2-2, Mariano Gutierrez, margutierrez75@gmail.com" << endl;
    fstream file(argv[1]); // input file
    Tokenizer *makeTokens = new Tokenizer();
    std::vector<string> *vecTokens = new vector<string>();
    std::vector<string> *tokContainer = new vector<string>();
    int lineNum = 1;
    std::string line;
    while(!file.eof()) {
        getline(file,line); // gets the first line  and sticks it into line var
        try {
            makeTokens -> Tokenize(line); // tokenize the first line // calls tokenize function on the single line
        }
        catch(string e) {
            std::cout << "Error on line " << lineNum << ": " << e <<std::endl; // e is the error from tokenize.
            return 0;
        }
        try {
            *vecTokens =  *makeTokens -> GetTokens(); // passes in a pointer to a reference with the first set of tokens
        }
        catch(string e) {
            std:: cout << e << std::endl;
            return 0;
        }
        for(int i = 0; i < vecTokens -> size(); i++) {
            tokContainer->push_back(vecTokens -> at(i));
        }
        lineNum++;
        tokContainer -> push_back("\0"); // to know when to print
    }

    for(int i = 0; i < tokContainer -> size(); i++) {
    if(tokContainer -> at(i) == "\0") {
        cout << endl;
    }
    else if( i < tokContainer -> size() && tokContainer -> at(i + 1) == "\0") {
        cout << tokContainer -> at(i);
    }
    else {
        cout << tokContainer->at(i) << ",";
    }
}
    // memory management
    delete makeTokens;
    delete vecTokens;
    delete tokContainer;
    return 0;

}
