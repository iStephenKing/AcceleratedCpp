/*
 
 Accelerated C++ Chapter 10
 By Koenig and Moo
 
 Test for Student_info Class
 
 Stephen King
 11/19/17
 */

#include <iostream>
#include <vector>
#include <string>
#include "Student_info.h"

using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info record; // Defaut initialization
    string::size_type maxlen = 0;
    
    // read and store the date
    
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }
    
    sort(students.begin(), students.end(), compare);
    
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        
        cout << students[i].name()
        << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            if (students[i].valid()) {
                /*
                char* s = students[i].letter_grade();
                cout << " " << s << endl;
                delete[] s;
                 */
                cout << " " << students[i].letter_grade() << endl;
            }
            else
                cout << " is a slacker" << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
        
    }
    return 0;
}