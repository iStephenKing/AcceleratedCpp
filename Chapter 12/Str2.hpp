#ifndef GUARD_STR2_H
#define GUARD_STR2_H
/* 
    Str.hpp
    
    From Accelerated C++
    by Andrew Koenig and Barbara E. Moo
 
    Simplified version of library string class
 
    Stephen King
    11/25/17
 */

#include <cstring>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <memory>

class Str {
    
    friend std::istream& operator>>(std::istream&, Str&);
    friend std::istream& getline(std::istream&, Str&);
    
public:
    typedef char* iterator;
    typedef const char* const_iterator;
    typedef size_t size_type;
    typedef char value_type;
    typedef char& reference;
    typedef const char& const_reference;
    
    // Default Constructor; create an empty Str
    Str() { create(); }
    
    // Create an Str containing copies of c
    Str(size_type n, char c) { create(n,c); }
    
    // Create an Str from a null terminated charater array
    Str(const char * cp) { create(cp, cp+strlen(cp)); }
    
    // Copy Constructor
    Str(const Str& s) { create(s.begin(), s.end()); }
    
    // Create an Str from the range denoted by iterators b and e
    template<class In> Str(In b, In e) { create(b,e); }
    
    // Destructor
    ~Str() { uncreate(); }
    
    void clear() { uncreate(); create(); }
    
    size_type size() const { return length; }
    bool empty() const { return length == 0; }
    
    operator bool() const { return ! empty(); }
    char& operator[](size_type i) { return chars[i]; }
    const char& operator[](size_type i) const { return chars[i]; }
    
    Str& operator=(const Str&);
    Str& operator+=(const Str&);
    
    const char* c_str() const { return chars; }

    const char* data() const { return chars; }
    
    iterator begin() { return chars; }
    const_iterator begin() const { return chars; }
    
    iterator end() { return chars + length; }
    const_iterator end() const { return chars + length; }
    
private:
    iterator chars;  // First Character
    size_type length; // One past last character in array
    
    // Facilitates memory allocation
    std::allocator<char> alloc;
    
    void create();
    void create(size_type n, const char c);
    template <class In> void create(In b, In e);
    //void create(const_iterator b, const_iterator e);
    
    // Destroy elelements in array and free memory
    void uncreate();
    
};


std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);
bool operator<(const Str&, const Str&);
bool operator<=(const Str&, const Str&);
bool operator>=(const Str&, const Str&);
bool operator>(const Str&, const Str&);
bool operator==(const Str&, const Str&);
bool operator!=(const Str&, const Str&);






#endif