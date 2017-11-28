#ifndef GUARD_STR_H
#define GUARD_STR_H
/* 
    Str.hpp
    
    From Accelerated C++
    by Andrew Koenig and Barbara E. Moo
 
    Simplified version of library string class
 
    Stephen King
    11/25/17
 */

#include "Vec.h"
#include <cstring>
#include <iterator>
#include <algorithm>
#include <iostream>

class Str {
    friend std::istream& operator>>(std::istream&, Str&);
    
public:
    typedef Vec<char>::size_type size_type;
    
    // Default Constructor; create an empty Str
    Str() { }
    
    // Create an Str containing copies of c
    Str(size_type n, char c): data(n,c) { }
    
    // Create an Str from a null terminated charater array
    Str(const char * cp) {
        std::copy(cp, cp+strlen(cp), std::back_inserter(data));
    }
    
    // Create an Str from the range denoted by iterators b and e
    template<class In> Str(In b, In e) {
        std::copy(b,e, std::back_inserter(data));
    }
    
    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }
    
    size_type size() const { return data.size(); }
    
    Str& operator+=(const Str& rhs);
    
private:
    Vec<char> data;
};


std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);


#endif