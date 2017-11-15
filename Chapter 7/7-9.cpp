/*
 7-9.cpp
 
 Playground for testing code for nrand
 From Chapter 7 of Accelerated C++
 
 Stephen King
 11/12/17
 */

#include <algorithm>
#include <iostream>
#include <climits>

#define TEST_MAX 32767

using namespace std;

int nrand(int n); // Only pass up to TEST_MAX
int bigrand(int n); // Full Value

int main()
{
    cout << "RAND_MAX = " << RAND_MAX << endl;
    cout << "INT_MAX = " << INT_MAX << endl;
    cout << "TEST_MAX = " << TEST_MAX << endl;
    
    // Test random value values between 1 and int max
    cout << "INT_MAX" << endl;
    for (int i = 0; i < 2000; ++i){
        cout << bigrand(INT_MAX) << " ";
        if (i%20 == 0)
            cout << endl;
    }
    cout << endl;
    
    cout << "100" << endl;
    for (int i = 0; i < 2000; ++i){
        cout << bigrand(100) << " ";
        if (i%20 == 0)
            cout << endl;
    }
    cout << endl;
}


// Return a random integer from 1 - n
// This implementation supports up to 2147483647
// Some implementations will only support up to 32767
int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    const int bucket_size = RAND_MAX / n;
    int r;
    do r = rand() / bucket_size;
    while (r >= n);
    
    return r;
}

int bigrand(int n)
{
    int chunks = n / TEST_MAX;
    int chunk = 0;
    if (chunks >= 1)
        chunk = nrand(chunks);
    return chunk * TEST_MAX + nrand(n % TEST_MAX);
}