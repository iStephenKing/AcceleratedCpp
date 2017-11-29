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
    Str(const char * cp) {
        create(cp, cp+strlen(cp));
    }
    
    // Copy Constructor
    Str(const Str& s) { create(s.begin(), s.end()); }
    
    // Destructor
    ~Str() { uncreate(); }
    
    void clear() { uncreate(); create(); }
    
    // Create an Str from the range denoted by iterators b and e
    template<class In> Str(In b, In e) {
        create(b,e);
    }
    
    size_type size() const { return avail - data; }
    bool empty() const { return data == avail; }
    
    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }
    
    Str& operator=(const Str&);
    Str& operator+=(const Str&);

    
    void push_back(const char val) {
        if (avail == limit)
            grow();
        unchecked_append(val);
    }
    
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    
    iterator end() { return avail; }
    const_iterator end() const { return avail; }
    
private:
    iterator data;  // First Character
    iterator avail; // One past last character in array
    iterator limit; // One past last allocated character
    
    // Facilitates memory allocation
    std::allocator<char> alloc;
    
    void create();
    void create(size_type n, const char c);
    void create(const_iterator b, const_iterator e);
    
    // Destroy elelements in array and free memory
    void uncreate();
    
    // Support functions for push_back()
    void grow();
    void unchecked_append(const char c);
};


std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);

void Str::create()
{
    data = avail = limit = 0;
}

void Str::create(size_type n, char c)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, avail, c);
}

void Str::create(const_iterator b, const_iterator e)
{
    data = alloc.allocate(e - b);
    limit = avail = std::uninitialized_copy(b,e,data);
}

// Destroy elelements in array and free memory
void Str::uncreate()
{
    if(data)
    {
        // Destroy! (in reverse order elements that were constructed)
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);
        
        // Deallocate the space
        alloc.deallocate(data, limit-data);
    }
    
    data = limit = avail = 0;
}

// Support functions for push_back()
void Str::grow()
{
    // Allocate twice as much space as currently in use
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    
    // Allocate space and copy existing elements into place -- TODO use std::move instead
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);
    
    // Free up old space
    uncreate();
    
    // Set pointers to new values
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

void Str::unchecked_append(const char c)
{
    alloc.construct(avail++, c);
}

Str& Str::operator=(const Str& rhs)
{
    if (&rhs != this)
    {
        uncreate();
        
        create(rhs.begin(), rhs.end());
    }
    
    return *this;
}

#endif