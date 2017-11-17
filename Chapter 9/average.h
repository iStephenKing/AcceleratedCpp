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

#include <vector>
#include <numeric>
#include <stdexcept>

template<class T>
T median(std::vector<T> v)
{
    typedef typename std::vector<T>::size_type vec_sz;
    
    vec_sz size = v.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");
    
    sort(v.begin(), v.end());
    
    vec_sz mid = size / 2;
    
    return size % 2 ? v[mid] : (v[mid] + v[mid -1]) / 2 ;
}

template<class T>
T mean(std::vector<T> v)
{
    return accumulate(v.begin(), v.end(), (T)0.0)/ v.size();
}

template<class T>
T optimistic_median(const std::vector<T>& vec)
{
    std::vector<T> nonzero;
    remove_copy(vec.begin(), vec.end(), back_inserter(nonzero), (T)0);
    
    typedef typename std::vector<T>::size_type vec_size;
    vec_size size = nonzero.size();
    if (size)
        return median(nonzero);
    else
        return 0;
}

#endif
