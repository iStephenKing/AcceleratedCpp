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
#include <map>
#include <fstream>

#include "grade.h"
#include "Student_info.h"

using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // Read and store all records, find length of longest name
    cout << "Reading Student Names and Grades" << endl;
    ifstream studentGrades;
    studentGrades.open("students.txt");
    if (studentGrades.is_open()) {
        while (read(studentGrades, record)) {
            maxlen = std::max(maxlen, record.name.size());
            students.push_back(record);
        }
        studentGrades.close();
    }
    
    cout << endl;
    map<const char, int> student_grades;
    // Calculate student Grades and Categorize
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        
        try {
            student_grades[letterGrade(students[i])]++; // Calculate letter grade, pass to map and increment int stored there
            
        } catch (domain_error e) {
            cout << e.what();
        }
    }
    
    cout << "The student grade breakdown is: " << endl;
    for (map<const char, int>::const_iterator it = student_grades.begin(); it != student_grades.end(); ++it)
        cout << it->first << ": " << it->second << endl;
    
    return 0;
    
}