/*
    From Accellerated C++

    This represents the median function

    Stephen King
    08/12/17
*/


// Source files
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "median.h"

using std::vector; using std::domain_error;

// compute the median of a vector<double>
// note: This function copies the entire vector (eek! no pointer!?)
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    
    sort(vec.begin(), vec.end());
    
    vec_sz mid = size/2;
    
    return size%2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}