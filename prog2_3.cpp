//
// Created by Mariano Gutierrez on 3/14/18.
//

#include "prog2_3.hpp"
/*
 *  Create a class called Parser (prog2_3.cpp and prog2_3.hpp). The Parser will have three public functions.
 *  The constructor, and destructor as appropriate and the boolean function Parse which will take a single vector<string> argument.
 *  The parse function will validate that the input adheres to the following rules.
 *
 *  If an input line is valid the function should return true.
 *  If it is invalid it should return false.
 *
 *  The following tokens must appear by themselves on a single line: pop, add, sub, mul, div, mod, skip
 *  Any other line  that contains a single token is invalid.
 *  The following tokens must appear on a single line of two tokens, in the correct order: push <int>  save <int> get <int> Any other input is invalid.
 */

using namespace std;

Parser::Parser() {
   //  the void
}

Parser::~Parser(){
    // none
}

bool Parser::Parse(vector<string> myVec) {
    if (myVec.at(0) == "pop" || myVec.at(0) == "add" || myVec.at(0) == "sub" || myVec.at(0) == "mul" ||
        myVec.at(0) == "div" || myVec.at(0) == "mod" || myVec.at(0) == "skip") { // end ugly if
            if(myVec.size() > 1) return false; //will always if we have the whole line
        /*for (int i = 1; i < myVec.size(); i++) { // if you have anything else
            if(myVec.at(i) == "\0") return false; // could do if == " " space character to ignore spaces
        } */
        return true;
    } // end big if
    else if (myVec.at(0) == "push" || myVec.at(0) == "save" || myVec.at(0) == "get") { // case of push, save, and get
        if(myVec.size() != 2) return false;
        for (int i = 0; i < myVec.at(1).size(); i++) {
           // if(myVec.at(1)[0] == '-') continue;
            // for the 2nd token check out to see if it's  an int, otherwise back out
            if (myVec.at(1)[i] < 48 || myVec.at(1)[i] > 57) { // ASCII syntatic sugarrr has 1,i
                return false;
            }
        } // end ascii validate for
        return true; // we checked the rest of the vec for any other input so we are ok
    }
    else {
        return false; // only valid input was allowed so dont really care
    }
}
