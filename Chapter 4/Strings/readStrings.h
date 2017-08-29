#ifndef GUARD_readStrings_h
#define GUARD_readStrings_h
/*
    readStrings.h

    declares a function readStrings to read input from an
    input stream and store words in a vector.
*/

#include <vector>
#include <string>
#include <iostream>


struct wordCount {
    std::string word;
    int count;
};

std::istream& readStrings(std::istream& in, std::vector<std::string>& wordList);
void parseWordList(std::vector<std::string> wordList, std::vector<wordCount>& words);
int maxLength(const std::vector<std::string>& wordList);
int maxLength(const std::vector<wordCount>& wordList);

#endif