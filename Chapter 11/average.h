#ifndef AVERAGE_H
#define AVERAGE_H
/*
    Average.h

    From Accelerated C++ By Koenig and Moo
    Chapter 8

    Defines template functions for finding averages

    Stephen King
    11/12/2017
*/

#include "Vec.h"
#include <algorithm>
#include <numeric>
#include <stdexcept>

template<class T>
T median(Vec<T> v)
{
    typedef typename Vec<T>::size_type vec_sz;
    
    vec_sz size = v.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");
    
    std::sort(v.begin(), v.end());
    
    vec_sz mid = size / 2;
    
    return size % 2 ? v[mid] : (v[mid] + v[mid -1]) / 2 ;
}


template<class T, class RandomAccessIterator>
T median(RandomAccessIterator first, RandomAccessIterator second)
{
    
 
    if (first == second)
        throw std::domain_error("median of an empty vector");
    
    Vec<T> v;
    copy(first, second, back_inserter(v));
    
    typedef typename Vec<T>::size_type vec_sz;
    
    vec_sz size = v.size();
    
    std::sort(v.begin(), v.end());
    
    vec_sz mid = size / 2;
    T ret = size % 2 ? v[mid] : (v[mid] + v[mid -1]) / 2 ;
    
    return ret;
}



template<class T>
T mean(Vec<T> v)
{
    return accumulate(v.begin(), v.end(), (T)0.0)/ v.size();
}

template<class T>
T optimistic_median(const Vec<T>& vec)
{
    Vec<T> nonzero;
    remove_copy(vec.begin(), vec.end(), back_inserter(nonzero), (T)0);
    
    typedef typename Vec<T>::size_type vec_size;
    vec_size size = nonzero.size();
    if (size)
        return median(nonzero);
    else
        return 0;
}

#endif
