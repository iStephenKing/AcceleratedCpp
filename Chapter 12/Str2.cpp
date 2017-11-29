/*
 Str.cpp
 
 From Accelerated C++
 by Andrew Koenig and Barbara E. Moo
 
 Simplified version of library string class
 
 Stephen King
 11/25/17
 */

#include "Str2.hpp"
#include <vector>

std::istream& operator>>(std::istream& is, Str& s)
{
    // Create Vector to read data into
    std::vector<char> vec;
    
    // Read and discard leading whitespace
    char c;
    while(is.get(c) && isspace(c));
    
    // Read until space or EOF
    if (is) {
        do vec.push_back(c);
        while (is.get(c) && !isspace(c));
        
        // If we read whitespace put it back on the stream
        if (is)
            is.unget();
    }
    
    //  Assign new Str to s from vector
    s = Str(vec.begin(), vec.end());
    
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


Str& Str::operator+=(const Str& rhs)
{
    // New Length is lhs + rhs
    size_type new_length = length + rhs.size();
    iterator new_data = alloc.allocate(new_length);
    
    // copy original string
    std::uninitialized_copy(data, data + length, new_data);
    
    // copy appended string
    std::uninitialized_copy(rhs.begin(), rhs.end(), new_data + length);
    
    // Free memory
    uncreate();
    
    // Set Private members
    length = new_length;
    data = new_data;
    
    return *this;
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

// Private Functions

// Default/ Empty create
void Str::create()
{
    data = 0;
    length = 0;
}

// Create with n copies of char
void Str::create(size_type n, char c)
{
    data = alloc.allocate(n);
    length = n;
    std::uninitialized_fill(data, data + length, c);
}

// Create from iterators
template <class In>
void Str::create(In b, In e)
{
    length = e - b;
    data = alloc.allocate(length);
    std::uninitialized_copy(b,e,data);
}

/*
 void Str::create(const_iterator b, const_iterator e)
 {
 length = e - b;
 data = alloc.allocate(length);
 std::uninitialized_copy(b,e,data);
 }
 */

// Destroy elelements in array and free memory
void Str::uncreate()
{
    if(data)
    {
        // Destroy! (in reverse order elements that were constructed)
        iterator it = data + length;
        while (it != data)
            alloc.destroy(--it);
        
        // Deallocate the space
        alloc.deallocate(data, length);
    }
    
    data = 0;
    length = 0;
}


/*
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
 */