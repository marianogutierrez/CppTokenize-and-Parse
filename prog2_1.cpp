#include "prog2_1.hpp" // same as C, no  <>'s  bc's not systems
#include <vector> // template stamping. Does not matter we included it twice
#include <queue> // more template stamping
#include <iostream>
#include <sstream> // take this string and consider it as a stream

using namespace std;

Tokenizer::Tokenizer() { // scope of the new class
    this -> data = new queue<vector<string> >(); // vector strings
}

Tokenizer::~Tokenizer() {
    delete this -> data;
}

// no need to check stuff regarding if first int
void Tokenizer::Tokenize(string Tokenize) {
    stringstream input(Tokenize); // token as a stream already delimited by spaces
    string store; // does get each by spaces
    while(!input.eof()) {
        input >> store; // takes a single token delimited by the space
        if(store == "push" ||  store == "pop" ||
           store == "add" || store  == "sub" || store == "mul" || store == "div" ||
           store  == "mod"|| store == "skip" || store == "save" || store == "get" ) {
            // push the token
            vector<string> tok1; // will be deleted once subroutine gone
            tok1.push_back(store);
            this -> data -> push(tok1); // FIFO
        }
        else { // 2nd check so must be
            for(int i = 0; i < store.length(); i++) {
                if(store[i] < 48 || store[i] > 57) { // ASCII
                    // if it's no integer... error!
                    throw "Unexpected token: " + store; // this is the error msg.
                }
            }
            vector<string> tok2;
            tok2.push_back(store);
            this -> data -> push(tok2);
            this -> lines++;
        }
    } // end while
} // end method

/*
The user is expected to call this method AFTER calling tokenize, other wise
an error will be thrown indicating that no tokens are available.
*/
vector<string>*Tokenizer::GetTokens() {
  /*  vector<string> *myvec = new vector<string>();
    if((this -> data -> empty())) {
        throw "No tokens";
    }
    while(!(this -> data -> empty())) {
        myvec -> push_back(this -> data -> front().at(0));
        this -> data -> pop();
    }
    return myvec; */
    //  ^^^^^In a panic I realizd after reading the directions again
    // I mucked it up before by returning the ENTIRE thing and not the set....
    // sad night no sleep.
    if((this -> data -> empty())) {
        throw "No tokens";
    }
      vector<string> *myvec = new vector<string>();
      vector<string> container = this -> data -> front(); // first set retrival

    for(int i = 0; i < container.size(); i++) {
      myvec -> push_back(container[i]);
    }
      this -> data -> pop();
      return myvec;
  }
