/*
 Str.cpp
 
 From Accelerated C++
 by Andrew Koenig and Barbara E. Moo
 
 Simplified version of library string class
 
 Stephen King
 11/25/17
 */

#include "Str.hpp"

std::istream& operator>>(std::istream& is, Str& s)
{
    // Clear out existing data -- data is private ! this won't work
    s.data.clear();
    
    // Read and discard leading whitespace
    char c;
    while(is.get(c) && isspace(c));
    
    // Read until space or EOF
    if (is) {
        do s.data.push_back(c);
        while (is.get(c) && !isspace(c));
        
        // If we read whitespace put it back on the stream
        if (is)
            is.unget();
    }
    
    return is;
    
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i) {
        os << s[i];
    }
    
    return os;
}

Str operator+(const Str& lhs, const Str& rhs)
{
    Str ret(lhs);
    ret += rhs;
    return ret;
}

