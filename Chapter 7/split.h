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

// Split a string into vector of words
std::vector<std::string> split(const std::string& str);

// Change string to lowercase characters
std::string condition(const std::string& str);



#endif