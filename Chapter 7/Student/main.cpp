/*
    From Accellerated C++

    We are calculated grades again, but now we use functions and later structs it sounds like

    Stephen King
    08/08/2017
*/
#include <iomanip>
#include <ios>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "grade.h"
#include "Student_info.h"

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;
using std::vector;  using std::domain_error;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // Read and store all records, find length of longest name
    cout << "Enter Student Names and Grades" << endl;
    while (read(cin, record)) {
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
    }
    
    cout << endl;
    // Alphabatize Student list
    sort(students.begin(), students.end(), less_than);
    
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        
        // Write student name and padding
        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
        
        // Compute Students Grade
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    
    return 0;
    
}