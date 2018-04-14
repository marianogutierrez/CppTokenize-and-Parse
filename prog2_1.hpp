
// Created by Mariano Gutierrez on 3/13/18.

/*Standard hpp file just like in C */
#include <queue>
#include <vector>
#include <string>

using namespace std;
class Tokenizer {

    // data structures that I may need
private:
    std::queue<vector<string> > *data; // a queue of vector strings...

public:
    Tokenizer();
    ~Tokenizer(); // addition of destructor for memory management.
    void Tokenize(string tokenize);
    vector<string>* GetTokens();
};
