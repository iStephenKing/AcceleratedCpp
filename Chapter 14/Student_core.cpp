/*
    From Acellerated C++
 
    Student_core.cpp
    Stephen King
    8/12/17
 */

#include "Student_core.hpp"
#include "grade.h"
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;


// Student core member function
// read in name, grades
istream& Student_core::read(istream& in)
{
    read_common(in);
    read_hw(in);

    return in;
}

double Student_core::grade() const
{
    return ::grade(midterm, final, homework);
}

std::string Student_core::letter_grade() const
{
    // range for letter grades and letter grades
    static const int grade_numbers[]   = { 97 , 94, 90 , 87 , 84, 80 , 77 , 74, 70 , 67 , 64, 60 , 0};
    static const char* const letters[] = {"A+","A","A-","B+","B","B-","C+","C","C-","D+","D","D-","F"};
    
    static const size_t ngrades = sizeof(grade_numbers) / sizeof(*grade_numbers);
    
    double student_grade = grade();
    
    for (size_t i = 0; i < ngrades; ++i) {
        if (student_grade >= grade_numbers[i])
            return letters[i];
    }
    
    return "\?\?\?";
}

// read in name, grades
istream& Student_core::read_common(istream& in)
{
    in >> n >> midterm >> final;
    
    return in;
}

// Read homework grades into hw vector
istream& Student_core::read_hw(istream& in)
{
    // use input stream to read grades into hw
    if (in) {
        // Empty Vector of any previous results
        homework.clear();
        
        // Read homework grades until EOF or invalid data
        string str;
        getline(in, str);
        stringstream input(str);
        double x;
        while (input >> std::dec >> x) //Is there a way to make this fail on a newline?
            homework.push_back(x);
        
        // Clear Error state for next read attempt
        in.clear();
    }
    
    return in;
}


// Nom member functions

// Predicate used to sort Students
bool compare(const Student_core& x, const Student_core& y)
{
    return x.name() < y.name();
}

bool compare_ptrs(const Student_core* student1, const Student_core* student2)
{
    return compare(*student1, *student2);
}

bool compare_grades(const Student_core& x, const Student_core& y)
{
    return x.grade() < y.grade();
}

vector<Student_core> classify_students(vector<Student_core>& students,
                                bool classifier(const Student_core&))
{
    vector<Student_core>::iterator iter = stable_partition(students.begin(), students.end(), classifier);
    vector<Student_core> failed(iter, students.end());
    students.erase(iter, students.end());
    
    return failed;
}

bool did_all_homework(const Student_core& s)
{
    return ((std::find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}
bool fgrade(const Student_core& s)
{
    return s.grade() < 60;
}
bool pgrade(const Student_core& s)
{
    return !fgrade(s);
}
