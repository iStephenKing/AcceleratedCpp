#ifndef SEARCH_STRING_H
#define SEARCH_STRING_H
/* 
    Defines helper functions to parse strings
 
    Code from Accelerated C++ by Andrew Koenig and Barbara E. Moo
 
    Stephen King
    8/28/17
 */

#include <string>
#include <vector>

bool isPalindrome(const std::string& s);
std::vector<std::string> find_urls(const std::string& s);

std::string::const_iterator
url_beg(std::string::const_iterator b, std::string::const_iterator e);

std::string::const_iterator
url_end(std::string::const_iterator b, std::string::const_iterator e);

#endif