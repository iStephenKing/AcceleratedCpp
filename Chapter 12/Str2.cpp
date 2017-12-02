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
    // Create Vector to read chars into
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

std::istream& getline(std::istream& is, Str& s)
{
    // Vector to read chars into
    std::vector<char> vec;
    
    // Read until Newline or EOF
    // If newline take off of istream but do not store
    char c;
    while(is.get(c) && c != '\n')
        vec.push_back(c);
    
    s = Str(vec.begin(), vec.end());
    
    return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    /*
    for (Str::size_type i = 0; i != s.size(); ++i) {
        os << s[i];
    }
     */
    std::ostream_iterator(data, data + length);
    
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
    iterator new_chars = alloc.allocate(new_length);
    
    // copy original string
    std::uninitialized_copy(chars, chars + length, new_chars);
    
    // copy appended string
    std::uninitialized_copy(rhs.begin(), rhs.end(), new_chars + length);
    
    // Free memory
    uncreate();
    
    // Set Private members
    length = new_length;
    chars = new_chars;
    
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
    chars = 0;
    length = 0;
}

// Create with n copies of char
void Str::create(size_type n, char c)
{
    chars = alloc.allocate(n);
    length = n;
    std::uninitialized_fill(chars, chars + length, c);
}

// Create from iterators
template <class In>
void Str::create(In b, In e)
{
    length = e - b;
    chars = alloc.allocate(length);
    std::uninitialized_copy(b,e,chars);
}

// Destroy elelements in array and free memory
void Str::uncreate()
{
    if(chars)
    {
        // Destroy! (in reverse order elements that were constructed)
        iterator it = chars + length;
        while (it != chars)
            alloc.destroy(--it);
        
        // Deallocate the space
        alloc.deallocate(chars, length);
    }
    
    chars = 0;
    length = 0;
}


// Inequality and Relational operator pass work to strcmp
// strcmp returns a negative interger if left < right
// strcmp returns 0 if left and right are equal
// strcmp return a positive iteger if left > right
bool operator<(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator>(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator==(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}
