/*

    sentence.cpp
    
    From Accellerated C++ by Koenig and Moo
 
    Implements Functions for Automatic Sentence Generation
    Using Mapping to implement Grammer
    
    Stephen King
 */

 #include "sentence.h"

 using namespace std;

 typedef vector<string> Rule;
 typedef vector<Rule> Rule_collection;
 typedef map<string, Rule_collection> Grammer;

 Grammer
 