/*

    Accelerated C++ Chapter 11

    main.cpp

    Space for testing Chapter Examples
*/

#include "Vec.h"
#include <iostream>
#include <string>
#include "Student_info.h"

using namespace std;

int main()
{
    string s;
    Vec<string> v;
    while (getline(cin, s)) {
        v.push_back(s);
    }
    
    for (Vec<string>::const_iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;
    

    
}