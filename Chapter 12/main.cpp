/*

    Main Function to test chapter programs

    From Accelerated C++ 
    By Andrew Koenig and Barbara E. Moo

    Stephen King
    11/28/17
*/

#include <iostream>
#include <cassert>
#include "Str2.hpp"
#include "Vec.h"
#include <algorithm>

using namespace std;

int main()
{
    Str s1 = "Hello World!";
    
    Str s2 = "ABC";
    
    Str s3 = "AAA";
    
    Str s5;
    
    for (Str::const_iterator it = s1.begin(); it != s1.end(); ++it)
        cout << *it;
    cout << endl;
    
    // These statements should pass
    assert(s1 == s1);
    
    assert(s3 < s2);
    
    assert(s2 > s3);
    
    assert(s2 >= s3);
    
    assert(s3 <= s2);
    
    assert(s1 >= s1);
    
    assert(s1 <= s1);
    
    assert(s1);
    
    assert(!s5);
    
    Str s4 = "Positive Cases Passed";
    
    cout <<  s4 << endl;
    
    Str s;
    getline(cin, s);
    cout << s<< endl;
    
    //assert(s1 == s2);
    
    //cout << "Negative Case Passed" << endl;
    
    Vec<char> v(s4.begin(), s4.end());
    ostream_iterator<char> out(cout, " ");
    copy(v.begin(), v.end(), out);
    cout << endl;
    
    
}