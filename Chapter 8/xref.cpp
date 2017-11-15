/*
    xref.cpp
    
    Implements funcion xref
 
    Takes in access to an input stream and returns a map of strings to a vector of where
    that string appeared in the input stream.
*/

#include "xref.h"

using namespace std;

std::map<std::string, std::vector<int> >
    xref(std::istream& in,
         std::vector<std::string>find_words(const std::string&))
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;
    
    // Read the next line from input stream
    while (getline(in, line)) {
        ++line_number;
    
        // Break the input line into individual words
        vector<string> words = find_words(line);
    
        // Remember that each word has occured on the current line
        string word;
        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
            word = *it;//condition(*it);
            if (ret[word].empty() || ret[word].back() != line_number)
                ret[word].push_back(line_number);
        }
    }
    return ret;
    
}

bool compare_wordcount(std::pair<std::string, int> left, std::pair<std::string, int> right)
{
    return (left.second > right.second) ||
           ((left.second == right.second) && (left.first < right.first));
}

string::size_type max_key_length(std::map<std::string, std::vector<int> > m)
{
    string::size_type max_length = 0;
    for (map<string, vector<int> >::const_iterator it = m.begin(); it != m.end(); ++it )
        max_length = max(max_length, it->first.length());
    
    return max_length;
}
