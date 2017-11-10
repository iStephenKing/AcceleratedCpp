#ifndef XREF_H
#define XREF_H
/*
    xref.h defines the xref function
    
    Takes in access to an input stream and returns a map of strings to a vector of where
    that string appeared in the input stream.
*/

#include "split.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>

std::map<std::string, std::vector<int> >
    xref(std::istream& in,
         std::vector<std::string>find_words(const std::string&) = split);


#endif
