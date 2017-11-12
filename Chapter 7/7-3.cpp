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

    // Call to xref using default (split)
    ifstream textFile;
    textFile.open("text.txt");
    map<string, vector<int> > ret;
    if (textFile.is_open()) {
        ret = xref(textFile);
        textFile.close();
    }
    string::size_type width = max_key_length(ret);
    
    // Write out the results
    for (map<string, vector<int> >::const_iterator it = ret.begin();
         it != ret.end(); ++it) {
    
        // Write the word
        cout << setw(width) << it->first << ": "; // << " occurs on line(s): ";
    
        // Write the first line numbers
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it++;
    
    
        // Write the remaining line numbers, if any
        int n = 0;
        while (line_it != it->second.end()) {
            if  (n++ == 25 )
            {
                cout << endl << setw(width) << "" << "  ";
                cout << *line_it++;
                n = 0;
            } else
                cout << ", " << *line_it++;
            
        }
    
        // Write a newline to seperate words
        cout << endl;
    }
    
    return 0;
}