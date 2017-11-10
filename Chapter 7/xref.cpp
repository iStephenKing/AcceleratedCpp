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
    
        // Remember that each words has occured on the current line
        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
            ret[*it].push_back(line_number);
        }
    }
    return ret;
    
}
