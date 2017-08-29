//
//  HelloWorld.cpp
//  
//
//  Created by Stephen King on 8/4/2017
//
//

#include <iostream>
#include <string>

int main()
{
    using namespace std;
    
    string line;
    if (!getline(cin, line)) {
        return -1;
    }
    
    istringstream iss(line);
    string s1;
    while  ((iss >> s1)) {
        cout << s1 << endl;
    }
    
    
    return 0;
}
