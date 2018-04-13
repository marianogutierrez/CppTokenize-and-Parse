//
// Created by Mariano Gutierrez on 3/15/18.
//

/*
 *  Create a driver that tokenizes all of the input lines and then parses all of the input lines.
 *  All of the input should be completely tokenized before any parsing should be done.
 *  On tokenization error your program should print an error as in prog2_2.
 *  On parsing error your program should print: “Parse error line <#>: <line>” and your program should stop executing.
 *  When all input in valid it should be printed line by line with commas separating the tokens.
 */

#include <iostream>
#include <sstream> // take this string and consider it as a stream
#include <vector>  // arraylist
#include <fstream> // file stream
#include "prog2_3.hpp"
#include "prog2_1.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "Assignment #2-4, Mariano Gutierrez, margutierrez75@gmail.com" << endl;
    if (argc != 2) return 0; // end it. you broke my stuff

    int lineNum = 1;
    fstream file(argv[1]); // input file
    string line; // the line
    string store; // temp variable to hold a single string from line
    string badLine = "";
    bool indicator = true;
    int badLineNum = 1;


    vector<string> vecStore; // allocated on the stack so no memory management is necessary
    vector<string> vecStoretemp; // allocated on the stack so no memory management is necessary
    Tokenizer* tokenize = new Tokenizer();
    Parser* parseIt = new Parser(); // parse with parse() subroutine

    while(!file.eof()) {
        getline(file,line); // gets the first line  and sticks it into line var
        try {
            makeTokens -> Tokenize(line); // tokenize the first line // calls tokenize function on the single line
        }
        catch(string e) {
            std::cout << "Error on line " << lineNum << ": " << e <<std::endl; // e is the error from tokenize.
            return 0;
        }
        lineNum++;
      }

/*
    while(!file.eof()) {
        // tokenize all lines
        getline(file, line);
        stringstream stream(line); // constructor call made on the stack
        // also splits things by space
            while(!stream.eof()) {
                stream >> store; // take the single string delimited by the space
                if (store == "pop" || store == "add" || store == "sub" || store == "mul" ||
                    store == "div" || store == "mod" || store == "skip") {
                    // push the token, because it is legitimate
                    vecStore.push_back(store);
                   // vecStoretemp.push_back(store);
                    // the end of this marks the end of a valid line in the token
                }
                else if((store == "push" || store == "save" || store == "get")) {
                    vecStore.push_back(store);
                    //vecStoretemp.push_back(store);
                }
                else { // for negative numbers. Use && with approraite condition logic i => 48 && i <= 57 (if (0) == '-' keep going
                    for(int i = 0; i < store.size(); i++) {
                       // if(store[0] == '-') continue;
                        if(store[i] < 48 || store[i] > 57) {
                            cout << "Error on line " << lineNum << ": " << "Unexpected token: " << store <<endl;
                            return 0;
                        }
                    }
                    vecStore.push_back(store); // legit
                   // vecStoretemp.push_back(store);
                }
            }
    lineNum++;
  }
  */
        string tmp;
        file.clear(); //remove eof bit flag
        file.seekg(0,ios::beg); // reset the file to begin at start once more because we are reusing it
        while(!file.eof()) {
            getline(file,line);
            stringstream oss(line);
            while(!oss.eof()) {
                oss >> tmp; // critical
                vecStoretemp.push_back(tmp);
            }

            indicator = parseIt->Parse(vecStoretemp);
            if(indicator == false) {
                cout << "Parse error on line " << badLineNum <<" : " << line ;
                return 0;
            }
            vecStoretemp.clear();
            badLineNum++;
        }


    // once all validated print it
    for(int i = 0; i < vecStore.size(); i+=2) {
        if(vecStore.at(i) == "pop" || vecStore.at(i) == "add" || vecStore.at(i) == "sub" ||
            vecStore.at(i) == "mul" || vecStore.at(i) == "div" || vecStore.at(i) == "mod"|| vecStore.at(i) == "skip") {
            cout << vecStore.at(i) << endl;
            i--;
        }
        else {
            cout << vecStore.at(i) << ","; //retrieve it! and put the comma and space
            if( i != vecStore.size() -1) {
                cout << vecStore.at(i + 1) << std::endl; //retrieve it!
            }
        }
    }
    delete parseIt;
    delete Tokenizer;
    parseIt = 0; // avoid dangling pointers. See Sebesta ch.6.12
    return 0;
}
