/*
 
    Test using hcat and frame with iterators

*/

#include "stringHelpers.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main () {
    
     string s;
     vector<string> vec;
    
     while (getline(cin, s))
         vec.push_back(s);
     
     vector<string> framedStrings = frame(vec);
     
     for (vector<string>::size_type i  = 0; i != framedStrings.size(); ++i)
     cout << framedStrings[i] << endl;
     
     cout << endl << "Vcat" << endl;
     vector<string> vertical = vcat(vec, framedStrings);
     for (vector<string>::size_type i = 0; i != vertical.size(); ++i)
     cout << vertical[i] << endl;
     
     cout << endl << "Hcat" << endl;
     vector<string> horizontal = hcat(vec, framedStrings);
     for (vector<string>::size_type i = 0; i != horizontal.size(); ++i)
     cout << horizontal[i] << endl;
     
     return 0;
     
     
}