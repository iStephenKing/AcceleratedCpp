/*

    main.cpp
    
    Accelerated C++ Chapter 10-3
    By Andrew Koenig and Barbara E. Moo

    Test median with array

    Stephen King
    11/17/17
*/

#include <iostream>
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
    
    
    return 0;

}

