#ifndef GUARD_SPLIT_H
#define GUARD_SPLIT_H
/*
    Split.h
 
    Refactor Split from previous chapters
    Implement functions with iterators
 */

#include <cctype>
#include <vector>
#include <string>

// Test if character is whitespace
bool space(char c);

// Test if character is not whitespace
bool not_space(char c);

// Split a string into words
template <class Out>
void split(const std::string& str, Out os)
{
    typedef std::string::const_iterator iter;
    
    iter i = str.begin();
    while (i != str.end()) {
        i = find_if(i, str.end(), not_space);
        iter j = find_if(i, str.end(), space);
        if (i != str.end())
            *os++ = std::string(i,j);
        i = j;
    }
}

// Change string to lowercase characters
std::string condition(const std::string& str);



#endif