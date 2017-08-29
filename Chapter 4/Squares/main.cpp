/*

    Squares.cpp
 
    This would need some serious work if it was meant to actually be used.
    1. Need to account for negative numbers
    2. Need to account for 1.03e+04 format

    Stephen King
    8/13/17
*/

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

std::streamsize getWidth(double value, int numDecimals);

int main()
{
    
    cout << "Enter min Value to square: ";
    double minSquare;
    cin >> minSquare;
    cout << "Enter max Value to square: ";
    double maxSquare;
    cin >> maxSquare;
    cout << "Enter the number of squares to compute: ";
    int numSquares;
    cin >> numSquares;
    cout << "Enter the number of decimals";
    int numDecimals;
    cin >> numDecimals;
    
    double step = (maxSquare - minSquare)/numSquares;
    if (minSquare < maxSquare)
    {
        int digits = getWidth(minSquare, numDecimals);
        int squaredigits = getWidth( maxSquare * maxSquare, numDecimals);
    
        for (double i = minSquare; i <= maxSquare; i+= step)
            cout << setw(digits + 2) << std::setprecision(digits) << i
                 << setw(squaredigits + 2) << std::setprecision(squaredigits) << i*i << setw(0) << endl;
    }else
        cout << "Min must be less than max";
}

std::streamsize getWidth(double value, int numDecimals){
    
    std::streamsize digits = numDecimals;
    int val = (int)value;
    
    while (val) {
        ++digits;
        val /= 10;
    }
    
    return digits;
}