//
//  Greetings.cpp
//
//
//  Created by Stephen King on 8/5/2017
//
//

#include <iostream>
#include <string>


int main ()
{
    // Could also use using std::cout; to be more explicit
    using namespace std;
    
    //Ask for a name
    cout << "Please enter your name:";
    string name;
    cin >> name;
    
   
    
    int rowpad = 1;
    //cout << "Enter row padding: ";
    //cin >> rowpad;
    int colpad = 1;
    //cout << "Enter col padding: ";
    //cin >> colpad;
    
    
    // Generate the greeting
    string space(colpad, ' ');
    const string greeting = "Hello, " + name + "!";
    
    // Total number of rows and collumns to write
    const int rows = rowpad * 2 + 3;
    const string::size_type cols = greeting.size() + colpad * 2 + 4;
    
    // Seperate output from input
    cout << endl;
    
    // invarient: we have written r rows so far
    for (int r = 0; r < rows; ++r) {
        
        // Iterate through collumns to write row
        string::size_type c = 0;
        // invarient: we have written 'c' character in the row
        while (c < cols) {
            if (r == rowpad + 1 && c == colpad + 1) {
                cout << greeting;
                c += greeting.size();
            }else {
                if (c == 0 || c == cols -1 ||
                    r == 0 || r == rows -1)
                    cout << "*";
                else
                    cout << " ";
                c++;
            }
        }
        cout << endl;
    }
    
    const int height = 5;
    
    //Square
    for (int i = 0; i != height; ++i)
        cout << string (2*height, '*') << endl;
    
    cout << endl;
    
    //Rectangle
    for (int i = 0; i != height; ++i)
        cout << string (4*height, '*') << endl;
    
    cout << endl;
    
    //Triangle
    for (int i = 0; i <= height; ++i)
    {
        cout << string(i,'*') << endl;
    }
    
    for (int i = 10; i >=-5; --i)
        cout << i << endl;
    
    int product = 1;
    for (int i  = 1; i <= 10; ++i)
        product *= i;
    cout << product << endl;
    
    int num1, num2;
    cout << "Enter an number: ";
    cin >> num1;
    cout << "Enter another number: ";
    cin >> num2;
    cout << ((num1 > num2)?num1:num2) << " is bigger" << endl;
    
    return 0;
}