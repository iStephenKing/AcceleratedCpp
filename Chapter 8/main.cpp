/*
    main.cpp

    Accellerated C++ By Koenig and Moo
    Chapter 8

    Stephen King
*/

#include <iterator>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include "split.h"

using namespace std;

int main()
{
    /*
    cout << "Input text: ";
    vector<int> v;
    
    // Read the inputs using istream_iterator
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    
    cout << endl;
    
    // Write the outputs using ostream_iterator
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    
    cout << endl;
    */
    cout << "Enter a line of text: ";
    string s;
    list<string> wordList;
    while(getline(cin,s))
        //split(s,ostream_iterator<string>(cout, "\n"));
        split(s,back_inserter(wordList));
    
    copy(wordList.begin(), wordList.end(), ostream_iterator<string>(cout, "\n"));
    
    return 0;
}