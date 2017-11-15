#ifndef SENTENCE_H
#define SENTENCE_H
/*
    Sentence.h
    
    From Accelerated C++
    By Koenig and Moo
    
    Defines Functions for Automatic Sentence Generation
    Using Mapping to implement Grammer
    
    Stephen King
*/


#include <string>
#include <vector>
#include <list>
#include <map>
#include <random>
#include <iostream>
#include <stdexcept>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammer;

// Read Grammer from a given input stream
Grammer read_grammer(std::istream& in);

// Determine if a given string represents a category
bool bracketed(const std::string& s);

template <class OutputIterator>
void gen_aux(const Grammer& g, const std::string& word, OutputIterator ot);

// return a random iteger in the range [0,n)
int nrand(int n);

template <class OutputIterator>
void gen_sentence(const Grammer& g, OutputIterator ot)
{
    gen_aux(g, "<sentence>", ot);
}

template <class OutputIterator>
void gen_aux(const Grammer& g, const std::string& word, OutputIterator ot)
{
    // Seed the psuedorandom number generator with current time
    
    if (!bracketed(word)) {
        *ot++ = word;
    }
    else {
        // Locate the rule that corresponds to the word
        Grammer::const_iterator it = g.find(word);
        if (it == g.end())
            throw std::logic_error("empty rule");
        
        // fetch the set of possible rules
        const Rule_collection& c = it->second;
        
        // select a random rule from collection
        int rand = nrand(c.size());
        const Rule& r = c[rand];
        
        // recursively expand the selected rule
        for (Rule::const_iterator it = r.begin(); it != r.end(); ++it)
            gen_aux(g, *it, ot);
    }
}








#endif