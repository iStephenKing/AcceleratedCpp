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
    
    //Ask for the persons name
    cout<<"Please Enter your name:";
    
    //Read input
    string name;
    cin >> name;
    
    //Build the greeting
    const string greeting = "Hello, " + name + "!";

    const std::string spaces(greeting.size(), ' ');
    const string second = "* " + spaces + " *";
    const std::string first(second.size(), '*');

    cout << first << endl;
    cout << second << endl;
    cout << "* " << greeting << " *" << endl;
    cout << second << endl;
    cout << first << endl;
    
    cout << "And What is yours?";
    cin >> name;
    cout << "Hello, "<< name << "; nice to meet you too" << endl;
    
    return 0;
}
