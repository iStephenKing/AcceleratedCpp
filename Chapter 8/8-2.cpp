/*
    Exercise 8-2.cpp

    Test custom implementation of library functions
 
    Stephen King
    11/13/17
 */

#include "8-2.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    
    string test = "abcdef";
    
    c_reverse(test.begin(), test.end());
    
    cout << test << endl;
    
    return 0;
}

 