/*
    gen_sentence.cpp

    From Accelerated C++
    By Koenig and Moo

    Defines main function to generate sentences

    Stephen King
*/

#include "sentence.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    srand(time(NULL));
    
    // Open a text file storing grammer
    ifstream grammerFile;
    grammerFile.open("grammer.txt");
    
    // generate the sentence
    list<string> sentence = gen_sentence(read_grammer(grammerFile));
    
    // write the first word, if any
    list<string>::const_iterator it = sentence.begin();
    if (!sentence.empty())
        cout << *it++;
    
    // write the rest of the words, each preceded by a space
    while (it != sentence.end())
        cout << " " << *it++;
    
    cout << endl;
    return 0;
}