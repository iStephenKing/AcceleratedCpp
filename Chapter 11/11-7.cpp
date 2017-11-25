/*
    11-7 

    Secondary Test case for Vec Class

    Stephen King
    11/25/17
*/

#include "Vec.h"
#include "split.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

int main()
{
    ifstream reader("test.txt");
    string s;
    Vec<string> v;
    while (getline(reader,s))
        split(s, back_inserter(v));
    
    Vec<string> v2(v);
    cout << "Whole text" << endl;
    copy(v.begin(),v.end(), ostream_iterator<string>(cout, " "));
    

    v.erase(v.begin() + (v.end() - v.begin()) / 2, v.end());
    cout << endl << "First half" << endl;
    copy(v.begin(),v.end(), ostream_iterator<string>(cout, " "));
    
    v2.erase(v2.begin(), v2.begin() + (v2.end() - v2.begin()) / 2);
    cout << endl << "Second half" << endl;
    copy(v2.begin(), v2.end(),ostream_iterator<string>(cout, " "));
    cout << endl;
    
    return 0;
}