/*

    sentence.cpp
    
    From Accellerated C++ by Koenig and Moo
 
    Implements Functions for Automatic Sentence Generation
    Using Mapping to implement Grammer
    
    Stephen King
*/

#include "sentence.h"
#include "split.h"
#include <exception>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

Grammer read_grammer(istream& in)
{
    Grammer ret;
    string line;
    
    // Read the input
    while (getline(in,line)) {
        
        // Split the input into words
        vector<string> entry;
        split(line, back_inserter(entry));
        if (!entry.empty())
            // Use the category to store the associated rule
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    
    return ret;
}


bool bracketed(const string& s)
{
    // Left Associative!  Check for size > 1 first
    // That means we wont try to ref s[-1] is size = 0
    return s.size() > 1 && s[0] == '<' && s[s.size() -1] == '>';
}

int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    const int bucket_size = RAND_MAX / n;
    int r;
    do r = rand() / bucket_size;
    while (r >= n);
    
    return r;
}