/*

    Main Function to test chapter programs

    From Accelerated C++ 
    By Andrew Koenig and Barbara E. Moo

    Stephen King
    11/28/17
*/

#include <iostream>
#include "Str2.hpp"

using namespace std;

int main()
{
    Str s1 = "Hello World!";
    cout << s1 << endl;
    cout << s1 << endl;
    cin >> s1;
    cout << s1 << endl;
    
    Str s2(5,'s');
    cout << s2 << endl;
    s1 = s2;
    cout << s1;
    s2 = "changed";
    cout << "s1 = " << s1 << " | s2 = " << s2 << endl;
    s2 += " again";
    cout << s2 << endl;
    cout << s1 + s2 + "pizza" + s1 << endl;
    
}