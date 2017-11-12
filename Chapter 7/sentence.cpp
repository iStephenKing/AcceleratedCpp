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

using namespace std;

Grammer read_grammer(istream& in)
{
    Grammer ret;
    string line;
    
    // Read the input
    while (getline(in,line)) {
        
        // Split the input into words
        vector<string> entry = split(line);
        if (!entry.empty())
            // Use the category to store the associated rule
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    
    return ret;
}

list<string> gen_sentence(const Grammer& g)
{
    list<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

bool bracketed(const string& s)
{
    // Left Associative!  Check for size > 1 first
    // That means we wont try to ref s[-1] is size = 0
    return s.size() > 1 && s[0] == '<' && s[s.size() -1] == '>';
}

void gen_aux(const Grammer& g, const string& word, list<string>& ret)
{
    // Seed the psuedorandom number generator with current time
    
    if (!bracketed(word)) {
        ret.push_back(word);
    }
    else {
        // Locate the rule that corresponds to the word
        Grammer::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");
        
        // fetch the set of possible rules
        const Rule_collection& c = it->second;
        
        // select a random rule from collection
        int rand = nrand(c.size());
        const Rule& r = c[rand];
        
        // recursively expand the selected rule
        for (Rule::const_iterator it = r.begin(); it != r.end(); ++it)
            gen_aux(g, *it, ret);
    }
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

