/*

    Accelerated C++ Chapter 9
    By Koenig and Moo

    Test for Student_info Class

    Stephen King
    11/15/17
 */

#include <iostream>
#include <iomanip>
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
        streamsize prec = cout.precision();
        
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            double final_grade = students[i].grade();
            cout << setprecision(3) << final_grade
            << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
        
    }
    return 0;
}
