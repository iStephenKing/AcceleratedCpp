/*
 
    Test space for chapter 6
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
    //string s;
   // getline(cin,s);
    
    /*
     // Find Palindromes
    vector<string> vec = split(s);
    
    for (vector<string>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " " << (isPalindrome(*it) ? "Palindrome" : "Not Palindrome" )<< endl;
     */
    
    /*
    // Find urls
    vector<string> urls = find_urls(s);
    for (vector<string>::const_iterator it = urls.begin(); it != urls.end(); ++it)
        cout << *it << endl;
     */
    
    /*
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
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "mean", mean_analysis, did, didnt);
    write_analysis(cout, "median of homework completed", optimistic_analysis, did, didnt);
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
    cout << endl;
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    // Compute Students Grade
    Student_infos failed_students;
    try {
        failed_students = extract_fails(students);
    } catch (domain_error e) {
        cout << e.what();
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    cout << "--Passed--" << endl;
    if (students.size())
        for (Student_infos::const_iterator iter = students.begin(); iter != students.end(); ++iter)
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
    cout << endl << numStudents << " Students" << endl
         << students.size() << " Passed" << endl
         << failed_students.size() << " Failed" << endl
         << "Computation time: " << duration << "us" << endl;
    
    
    return 0;
}