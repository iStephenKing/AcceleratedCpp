/*
    Exercise 11-5

    From Accelerated C++ By 
    Andrew Koenig and Barbara E. Moo

    Test "instrument" added to Student info class to check how often objects are created, copied or assigned

    Stephen King
    11/23/17
*/

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include "Student_info.h"
#include "Vec.h"

using namespace std;
using namespace std::chrono;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::domain_error;


int main()
{
    Vec<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    
    // Read and store all records, find length of longest name
    cout << "Enter Student Names and Grades" << endl;
    while (record.read(cin)) {
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
    }
    Vec<Student_info>::size_type numStudents = students.size();
    Vec<Student_info> students_copy(students);
    cout << endl;
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    // Compute Students Grade
    Vec<Student_info> slackers;
    try {
        slackers = classify_students(students, did_all_homework); //did_all_hw);
    } catch (domain_error e) {
        cout << e.what();
    }
    cout << "--Did Homework--" << endl;
    
    if (students.size())
        for (Vec<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter)
            cout << iter->name << endl;
    else
        cout << "None" << endl;
    cout << endl;
    cout << "--Slackers--" << endl;
    if (slackers.size())
        for (Vec<Student_info>::const_iterator iter = slackers.begin(); iter != slackers.end(); ++iter)
            cout << iter->name << endl;
    else
        cout << "None" << endl;
    
    
    // Compute Students Grade
    Vec<Student_info> failed_students;
    try {
        failed_students = classify_students(students_copy, pgrade);
    } catch (domain_error e) {
        cout << e.what();
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    cout << "--Passed--" << endl;
    if (students.size())
        for (Vec<Student_info>::const_iterator iter = students_copy.begin(); iter != students_copy.end(); ++iter)
            cout << iter->name << endl;
    else
        cout << "None" << endl;
    cout << endl;
    cout << "--Failed--" << endl;
    if (failed_students.size())
        for (Vec<Student_info>::const_iterator iter = failed_students.begin(); iter != failed_students.end(); ++iter)
            cout << iter->name << endl;
    else
        cout << "None" << endl;
    
    
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << endl << numStudents << " Students" << endl
    << students_copy.size() << " Passed" << endl
    << failed_students.size() << " Failed" << endl
    << students.size() << " Did all the homework" << endl
    << slackers.size() << " Are slackers" << endl
    << "Computation time: " << duration << "us" << endl;
    
    
    
    return 0;

}