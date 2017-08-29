/*
    From Accellerated C++ by Andrew Koenig and Barbara E. Moo

    Computes a Students Grades based on grades and homework

    Stephen King
    8/07/17
*/

#include <iomanip>
#include <ios>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;
using std::vector;

int main()
{
    // Ask for the Students name
    cout << "Please enter your name: ";
    string name;
    cin >> name;
    cout << "Hello, " + name + "!" << endl;
    
    // Ask for Students grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    
    // Ask for homework grades
    cout << "Please enter your homework grades, "
            "followed by end-of-file: ";
    
    // Variables to read grades
    double x;
    vector<double> homework;
    
    // invarient: homework contains all of grades so far
    while (cin >> x) {
        homework.push_back(x);
    }
    
    // Calculate Median
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    
    if (size == 0){
        cout << endl << "Please " "try " "again." << endl;
        return 1;
    }
    
    // Call sort -- std library? It this an operator? Overloaded with class definition?
    sort(homework.begin(), homework.end());
    
    
    //Calculate first quartile
    vec_sz quarter = size / 4;
    double quartile;
    int mod = size % 4;
    quartile = (mod == 1 || mod == 2) ? (homework[quarter] + homework[quarter -1]) /2: homework[quarter -1];
    cout << "First Quartile: " << quartile << endl;
    
    //Calculate median
    vec_sz mid = size / 2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];
    cout << "Median: " << median << endl;
    
    //Calculate last quartile
    quartile = (mod == 1 || mod == 2) ? (homework[quarter + mid] + homework[quarter + mid + 1]) /2: homework[quarter + 1];
    cout << "Third Quarter is: " << quartile << endl;
    
    // Write the result
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec) << endl;
    
    return 0;
}

