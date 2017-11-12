/*
    main.cpp

    Playground for testing code
    From Chapter 7 of Accelerated C++

    Stephen King
    9/21/17
*/

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "xref.h"

using namespace std;

int main()
{
    // Read wordlist from input
    string s;
    map<string, int> wordlist;
    ifstream textFile;
    textFile.open("text.txt");
    string::size_type width = 0;
    if (textFile.is_open()) {
        while (textFile >> s) {
            ++wordlist[condition(s)];
            if (width < s.length())
                width = s.length();
        }
        textFile.close();
    }
    // Copy wordlist into a vector to sort by Values
    vector<pair<string, int> > wordcount(wordlist.begin(), wordlist.end());
    sort(wordcount.begin(), wordcount.end(), compare_wordcount);
    
    string word;
    for (vector<pair<string, int> >::const_iterator it = wordcount.begin(); it != wordcount.end(); ++it) {
        word = it->first + ": ";
        cout << setw(width) << word << it->second << endl;
    }
    return 0;
    
}