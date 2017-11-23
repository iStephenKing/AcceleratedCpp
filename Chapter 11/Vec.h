#ifndef GUARD_VEC_H
#define GUARD_VEC_H
/*
    From Accelerated C++ by 
    Andrew Koenig and Barbara E. Moo
 
    Vec.h  Defines the class interferce for Vec,
    a simplified implementation of vector<T>
 
    Stephen King
    11/20/17 
*/

#include <memory>
#include <cstddef>
#include <algorithm>

template <class T> class Vec{
    
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    
    Vec() { create(); }
    explicit Vec(size_type n, const T& val = T()) { create(n, val); }
    
    Vec(const Vec& v) { create(v.begin(), v.end()); }
    Vec(const_iterator b, const_iterator e) { create(b,e); }
    Vec& operator=(const Vec& rhs);
    ~Vec() { uncreate(); }
    void clear() { uncreate(); create(); }
    
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    
    void push_back(const T& val) {
        if (avail == limit)
            grow();
        unchecked_append(val);
    }
    
    size_type size() const { return avail - data; }
    bool empty() const { return data == avail; }
    
    
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    
    iterator end() { return avail; }
    const_iterator end() const { return avail; }
    
    iterator erase(iterator it)
    {
        for (iterator i = it; i != avail; ++i) {
            alloc.destroy(i);
            if ((i + 1) != avail) alloc.construct(i, *(i + 1));
        }
        
        --avail;
        return it;
        
    }
    
    iterator erase(iterator first, iterator last)
    {
        ptrdiff_t space = last - first;
        for (iterator i = first; i != avail; ++i) {
            alloc.destroy(i);
            if ((i + space) != avail) alloc.construct(i, *(i+space));
        }
        avail -= space;
        return first;
    }
    

    
private:
    iterator data;  // First Element
    iterator avail; // One past last element in array
    iterator limit; // One past last allocated element
    
    // Facilitates memory allocation
    std::allocator<T> alloc;
    
    // Allocate and Initialize Array
    void create();
    void create(size_type n, const T& val);
    void create(const_iterator b, const_iterator e);
    
    // Destroy elelements in array and free memory
    void uncreate();
    
    // Support functions for push_back()
    void grow();
    void unchecked_append(const T& val);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    if (&rhs != this)
    {
        uncreate();
        
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T> void Vec<T>::create()
{
    data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, avail, val);
}

template <class T> void Vec<T>::create(const_iterator b, const_iterator e)
{
    data = alloc.allocate(e - b);
    limit = avail = std::uninitialized_copy(b,e,data);
}

// Destroy elelements in array and free memory
template <class T> void Vec<T>::uncreate()
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
template <class T> void Vec<T>::grow()
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

template <class T> void Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}



#endif