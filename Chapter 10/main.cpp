/*

    main.cpp
    
    Accelerated C++ Chapter 10
    By Andrew Koenig and Barbara E. Moo

    playing with pointers

    Stephen King
    11/17/17
*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int inc(int x);

int main(int argc, char** argv)
{
    
    int fail_count = 0;
    
    cout << endl << "Program Name = " << argv[0] << endl;
    
    for (int i = 1; i < argc; ++i) {
        ifstream file(argv[i]);
        if (file) {
            cout << argv[i] << " contents" << endl;
            string s;
            while (getline(file,s)) {
                cout << s << endl;
            }
        }else {
                clog << "cannot open file " << argv[i] << endl;
                fail_count++;
        }
    }
    
    return fail_count;
     /*
    int nums[100];
    int * en = nums +100;
    cout << sizeof(nums) / sizeof(*nums) << endl;
    *en = 101;
    cout << sizeof(nums) / sizeof(*nums) << endl;
    *(++en) = 102;
    cout << sizeof(nums) / sizeof(*nums) << endl;
    cout << nums[100] << endl;
    cout << nums[101] << endl;
    cout << nums[102] << endl;
    
    return 0;
      */
}

int inc(int x)
{
    return ++x;
}