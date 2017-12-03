//
//  main.cpp
//  
//
//  Created by Stephen King on 12/3/17.
//
//

#include "Student_info.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    // Base Student info Class test
    
    vector<Student_info> students;
    Student_info record;
    string::size_type max_name_length = 0;
    
    // read and store Student data
    while (record.read(cin)) {
        max_name_length = max(max_name_length, record.name().size());
        students.push_back(record);
    }
    
    // Compare predicate used to alphabetize by name
    sort(students.begin(), students.end(), compare);
    
    for (vector<Student_info>::const_iterator  it = students.begin(); it != students.end(); ++it) {
        cout << it->name() << string(max_name_length + 1 - it->name().size(), ' ');
        
        try {
            double final_grade = it->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }
    
    return 0;
    
}
