/*
 searchString.cpp
 
 From Accelerated C++ By Andrew Koenig and Barbara E. Moo
 Implementation of String Parsing functions with iterators
 
 Stephen King
 8/28/2017
 */

#include "searchString.h"

using namespace std;

bool isPalindrome(const std::string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

bool not_url_char(char c)
{
    // Characters, in addition to alpha numerics that can appear in a url
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

std::string::const_iterator
url_beg(std::string::const_iterator b, std::string::const_iterator e)
{
    static const string sep = "://";
    
    typedef string::const_iterator iter;
    
    // i will mark where the url identifier was found
    iter i = b;
    while ((i = search(i,e, sep.begin(), sep.end())) != e) {
        
        if (i != b && i + sep.size() != e) {
            
            // Find beginning of protocol name
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;
            
            // check that what we found is part of a semivalid url
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        // No url found with this seperator
        i += sep.size();
    }
    return e;
}

std::string::const_iterator
url_end(std::string::const_iterator b, std::string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}

vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    
    // Scan the entire string
    while ( b!= e) {
        
        // look for one or more letters followed by ://
        b = url_beg(b,e);
        
        // Found a url
        if (b != e) {
            
            // Find the end of the url
            iter after = url_end(b,e);
            
            // remember the URL
            ret.push_back(string(b,after));
            
            b = after;
        }
    }
    return ret;
}