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
#include <numeric>
#include <iterator>
#include "average.h"

using std::vector; using std::domain_error;

// compute the median of a vector<double>
// Copy the vector so we can sort it
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

//compute the mean of a vector<double>
double mean(const vector<double>& vec)
{
    return accumulate(vec.begin(), vec.end(), 0.0)/vec.size();
}

double optimistic_median(const vector<double>& vec)
{
    vector<double> nonzero;
    remove_copy(vec.begin(), vec.end(), back_inserter(nonzero), 0);
    
    vector<double>::size_type size = nonzero.size();
    if (size)
    {
        /*
        sort(nonzero.begin(), nonzero.end());
        vector<double>::size_type mid = size/2;
        return size%2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
         */
        return median(nonzero);
    }else
        return 0;
}

