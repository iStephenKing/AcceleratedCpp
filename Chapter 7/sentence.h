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
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammer;

Grammer