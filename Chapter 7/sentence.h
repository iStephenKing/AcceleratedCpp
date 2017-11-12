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

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammer;

// Read Grammer from a given input stream
Grammer read_grammer(std::istream& in);

// Use Grammer to generate a sentence
std::list<std::string> gen_sentence(const Grammer& g);

// Determine if a given string represents a category
bool bracketed(const std::string& s);

// Aux Function to generate output based on grammer rules
void gen_aux(const Grammer& g, const std::string& word, std::list<std::string>& ret);

// return a random iteger in the range [0,n)
int nrand(int n);

#endif