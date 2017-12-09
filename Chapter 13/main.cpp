//
//  main.cpp
//  
//
//  Created by Stephen King on 12/3/17.
//
//

#include "Student_info.hpp"
#include "Student_handle.hpp"
#include "Grad.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    
    ifstream input("students.txt");
    
    // Mixed Student info Class and Child Grad class test
    vector<Student_handle> students;
    Student_handle record;
    string::size_type max_name_length = 0;
    
    // read and store Student data
    while (record.read(input)) {
 
        max_name_length = max(max_name_length, record.name().size());
        students.push_back(record);
    }
    cout << "Done Reading" << endl;
    // Compare predicate used to alphabetize by name
    sort(students.begin(), students.end(), Student_handle::compare);
    
    for (vector<Student_handle>::const_iterator  it = students.begin(); it != students.end(); ++it) {
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
