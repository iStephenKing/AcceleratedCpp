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

using namespace std;

int main()
{
    Str s1 = "Hello World!";
    
    Str s2 = "ABC";
    
    Str s3 = "AAA";
    
    // These statements should pass
    assert(s1 == s1);
    
    assert(s3 < s2);
    
    assert(s2 > s3);
    
    assert(s2 >= s3);
    
    assert(s3 <= s2);
    
    assert(s1 >= s1);
    
    assert(s1 <= s1);
    
    Str s4 = "Positive Cases Passed";
    
    cout <<  s4 << endl;
    
    //assert(s1 == s2);
    
    //cout << "Negative Case Passed" << endl;
    
}