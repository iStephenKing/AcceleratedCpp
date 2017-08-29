/*
    Split.cpp

    From Accelerated C++ By Andrew Koenig and Barbara E. Moo
    Implementation of Split functions with iterators
 
    Stephen King
    8/28/2017
*/

#include <iostream>
#include <iterator>
#include <algorithm>

#include "split.h"

using namespace std;

// Test if character is whitespace
bool space(char c)
{
    return(isspace(c));
}

// Test if character is not whitespace
bool not_space(char c)
{
    return(!isspace(c));
}

// Split a string into vector of words
std::vector<std::string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    
    iter i = str.begin();
    while (i != str.end()) {
        i = find_if(i, str.end(), not_space);
        iter j = find_if(i, str.end(), space);
        if (i != str.end())
            ret.push_back(string(i,j));
        i = j;
    }
    return ret;
}

bool isPalindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
    string s;
    getline(cin,s);
    vector<string> vec = split(s);
    
    for (vector<string>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " " << (isPalindrome(*it) ? "Palindrome" : "Not Palindrome" )<< endl;
    
}