/*

    main.cpp
    
    Accelerated C++ Chapter 10-3
    By Andrew Koenig and Barbara E. Moo

    Test median with array

    Stephen King
    11/17/17
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>

#include "average.h"

using namespace std;


int main(int argc, char** argv)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7,8,9};
    size_t length = sizeof(nums) / sizeof(*nums);
    cout << "median of int nums[] = " << median<int>(nums, nums + length) << endl;
    
    for (int i = 0; i < length; ++i)
        cout << nums[i] << " ";
    cout << endl;
    
    vector<int> vec(nums, nums+length);
    cout << "median of vector<int> = " << median<int>(vec.begin(), vec.end()) << endl;
    
    for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;
    
    cout << fixed << setprecision(1);
    double dnums[] = {1.1, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    size_t dlength = sizeof(dnums) / sizeof(*dnums);
    cout << "median of double dnums[] = " << median<double>(dnums, dnums + dlength) << endl;
    
    for (int i = 0; i < dlength; ++i)
        cout << dnums[i] << " ";
    cout << endl;
    
    vector<double> dvec(dnums, dnums+dlength);
    cout << "median of vector<double> = " << median<double>(dvec.begin(), dvec.end()) << endl;
    
    for (vector<double>::const_iterator it = dvec.begin(); it != dvec.end(); ++it)
        cout << *it << " ";
    cout << endl;
    
    
    return 0;

}

