/*
 
 Accelerated C++
 Exercise 8-1
 
 */

#include "split.h"
#include "searchString.h"
#include "Student_info.h"
#include "grade.h"

#include <vector>
#include <string>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
     // Analyze grades
     
     vector<Student_info> did, didnt;
     Student_info student;
     
     // Read in records, and sort based on homework completion
     while (read(cin, student)) {
     
     if (did_all_hw(student))
     did.push_back(student);
     else
     didnt.push_back(student);
     }
     
     
     // check that groups are non empty
     if (did.empty()) {
     cout << "No Student did all the homework!" << endl;
     return 1;
     }
     if (didnt.empty()) {
     cout << "Every student did all the homework!" << endl;
     return 1;
     }
     
     // Anaylize different methods of calculating grades
     write_analysis(cout, "median", grade_aux, did, didnt);
     write_analysis(cout, "mean", mean_grade, did, didnt);
     write_analysis(cout, "median of homework completed", optimistic_grade, did, didnt);
     */
    
    // Classify Students
    
    // Read in list of Students
    Student_infos students;
    Student_info record;
    string::size_type maxlen = 0;
    
    
    // Read and store all records, find length of longest name
    cout << "Enter Student Names and Grades" << endl;
    while (read(cin, record)) {
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
    }
    Student_infos::size_type numStudents = students.size();
    vector<Student_info> students_copy(students);
    cout << endl;
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    // Compute Students Grade
    Student_infos slackers;
    try {
        slackers = classify_students(students, did_all_hw);
    } catch (domain_error e) {
        cout << e.what();
    }
    cout << "--Did Homework--" << endl;
    
    if (students.size())
        for (Student_infos::const_iterator iter = students.begin(); iter != students.end(); ++iter)
            cout << iter->name << endl;
    else
        cout << "None" << endl;
    cout << endl;
    cout << "--Slackers--" << endl;
    if (slackers.size())
        for (Student_infos::const_iterator iter = slackers.begin(); iter != slackers.end(); ++iter)
            cout << iter->name << endl;
    else
        cout << "None" << endl;
    
    
    // Compute Students Grade
    Student_infos failed_students;
    try {
        failed_students = classify_students(students_copy, pgrade);
    } catch (domain_error e) {
        cout << e.what();
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    cout << "--Passed--" << endl;
    if (students.size())
        for (Student_infos::const_iterator iter = students_copy.begin(); iter != students_copy.end(); ++iter)
            cout << iter->name << endl;
    else
        cout << "None" << endl;
    cout << endl;
    cout << "--Failed--" << endl;
    if (failed_students.size())
        for (Student_infos::const_iterator iter = failed_students.begin(); iter != failed_students.end(); ++iter)
            cout << iter->name << endl;
    else
        cout << "None" << endl;
    
    
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << endl << numStudents            << " Students"             << endl
                 << students_copy.size()   << " Passed"               << endl
                 << failed_students.size() << " Failed"               << endl
                 << students.size()        << " Did all the homework" << endl
                 << slackers.size()        << " Are slackers"         << endl;
    cout << "Computation time: "<< duration << "us"<< endl;
    
    
    
    return 0;
    
}