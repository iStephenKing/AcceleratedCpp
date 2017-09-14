/* 

    Accelerate Cpp

    Problem 6.3
    Problem 6.4
*/

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    
    vector<int> u(10,100);
    vector<int> v;
    
    // This doesn't work. vector v is uninitialized.
    copy(u.begin(), u.end(), v.begin());
    
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << endl;
    }
    
    return 0;
}