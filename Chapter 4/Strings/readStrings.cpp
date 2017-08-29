/*
    readStrings.cpp

    defines the function readStrings.cpp

    Stephen King
    8/14/17
*/

#include "readStrings.h"
#include <algorithm>

using std::istream; using std::string; using std::vector;

std::istream& readStrings(std::istream& in, std::vector<std::string>& wordList)
{
    std::string word;
    while (in >> word) {
        wordList.push_back(word);
    }
    
    return in;
}

void parseWordList(std::vector<std::string> wordList, std::vector<wordCount>& words)
{
    // First sort the copy of the wordList
    sort(wordList.begin(), wordList.end());
    
    // Clear the existing list
    words.clear();
    
    // Read in the First Word
    wordCount word;
    word.word = wordList[0];
    word.count = 1;
    
    // invarient we have read 1 words so far
    vector<wordCount>::size_type i;
    for (i = 1; i <= wordList.size(); ++i){
        if (wordList[i] == word.word)
            ++ word.count;
        else{
            words.push_back(word);
            word.word = wordList[i];
            word.count = 1;
        }
    }
}

int maxLength(const std::vector<std::string>& wordList)
{
    int maxSize = 0;
    for (vector<string>::size_type i = 0; i <= wordList.size(); ++i)
        if (wordList[i].size() > maxSize)
            maxSize = wordList[i].size();
    return maxSize;
}

int maxLength(const std::vector<wordCount>& wordList)
{
    int maxSize = 0;
    for (vector<wordCount>::size_type i = 0; i <= wordList.size(); ++i)
        if (wordList[i].word.size() > maxSize)
            maxSize = wordList[i].word.size();
    return maxSize;
}