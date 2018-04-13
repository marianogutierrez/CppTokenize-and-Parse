Mariano Gutierrez
margutierrez75@gmail.comm

Files Included:

prog2_1.cpp
prog2_1.hpp
prog2_2_.cpp
prog2_3.cpp
prog2_3.hpp
prog2_4.cpp
README.md
cs320programmingrubric.pdf

prog2_1.cpp/prog2_1.hpp/prog2_2.cpp:

Example compilation: g++ prog2_2.cpp prog2_1.cpp -o prog2_2

prog2_1.cpp && prog2_1.hpp:
This program makes use the header file prog2_1.hpp in order to implement a
a Tokenizer object with a Tokenize and a GetTokens method.
These methods tokenize, hence there name, text by ensuring that the text is valid
according to the given legal words. The Tokenizer is implemented using a queue
in order to ensure FIFO behavior, and consists of a queue of vector strings, in
order to simplify the logic (avoid using cumbersome string operations to get
it to print correctly). Additionally, this program relies heavily on the string stream
function in c++ to delimit the line by spaces and properly check each word in the
line of code fed into it. The program also allows numbers by checking ascii values.

prog2_2.cpp:
This program looks for a file as its command line argument and tokenizes the text
using error checking to mitigate any issues. Then it prints out the text separated by commas
line by line.

 prog2_3.cpp/prog2_3.hpp/prog2_4.cpp:

 Example compilation: g++ prog2_4.cpp prog2_3.cpp prog2_1.cpp -o prog2_4

 prog2_3.cpp  && prog2_3.hpp:
 This program makes use of the header file to create a Parser object. This object does not make
 use of any instance fields, but does have a bool parse method. The program parses
 to ensure proper order of syntax using a similar methodology as prog2_2.

 prog2_4.cpp:
 This program is far more complex. It tokenize an input file
 sent from the command line argument and then makes use of a parser object to
 ensure correctness.
 Of interest is the following code:
 string tmp;
 file.clear(); //remove eof bit flag
 file.seekg(0,ios::beg); // reset the file to begin at start once more because we are reusing it

 This code takes the file resets the pointer to go back to the beginning of the file to
 begin parsing. This is necessary as the file was read once already from tokenizing.
 Finally, the text is printed from the input comma separated line by line.
