/* 

    Problem 6-9

    Use a library algorith to concatenate all
    memberbs of a vector<string>

    Stephen King
    9/18/17
*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


int main()
{
    // Lets start by reading in some strings from std in
    string s;
    vector<string> daStrings;
    while (cin >> s)
        daStrings.push_back(s);
    
    // Now concatenate them
    string bigString = accumulate(daStrings.begin(), daStrings.end(), s);
    cout << bigString << endl;
}

