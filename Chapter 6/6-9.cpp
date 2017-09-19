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
#include <functional>

using namespace std;

string bigString;
// I give up, making this crap global for now, maybe someting involving lambda? worth doubling back
void cat(string s)
{
    bigString += s;
}

int main()
{
    // Lets start by reading in some strings from std in
    string s;
    vector<string> daStrings;
    while (cin >> s)
        daStrings.push_back(s);
    
    // Now concatenate them
    for_each(daStrings.begin(), daStrings.end(), cat);
    cout << bigString << endl;
}

