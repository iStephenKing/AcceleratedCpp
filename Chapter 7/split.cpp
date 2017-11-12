/*
    Split.cpp

    From Accelerated C++ By Andrew Koenig and Barbara E. Moo
    Implementation of Split functions with iterators
 
    Stephen King
    8/28/2017
*/

#include <iostream>
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

// Change string to lowercase characters and remove punctuation
std::string condition(const std::string& str)
{
    string ret;
    for (string::const_iterator i = str.begin(); i != str.end(); ++i)
        if (isalpha(*i))
            ret.push_back(tolower(*i));
    
    return ret;
}
