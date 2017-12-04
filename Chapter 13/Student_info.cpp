/*
    From Acellerated C++
 
    Student_info.cpp
    Stephen King
    8/12/17
 */

#include "Student_info.hpp"
#include "grade.h"
#include <algorithm>
#include <iterator>

using namespace std;


// Student info member function
// read in name, grades
istream& Student_info::read(istream& in)
{
    read_common(in);
    read_hw(in);

    return in;
}

double Student_info::grade() const
{
    return ::grade(midterm, final, homework);
}

std::string Student_info::letter_grade() const
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
istream& Student_info::read_common(istream& in)
{
    in >> n >> midterm >> final;
    
    return in;
}

bool compare_ptrs(const Student_info* student1, const Student_info* student2)
{
    return compare(*student1, *student2);
}

// Read homework grades into hw vector
istream& Student_info::read_hw(istream& in)
{
    // use input stream to read grades into hw
    if (in) {
        // Empty Vector of any previous results
        homework.clear();
        
        // Read homework grades until EOF or invalid data
        double x;
        while (in >> std::dec >> x)
            homework.push_back(x);
        
        // Clear Error state for next read attempt
        in.clear();
    }
    
    return in;
}


// Nom member functions

// Predicate used to sort Students
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}

bool compare_grades(const Student_info& x, const Student_info& y)
{
    return x.grade() < y.grade();
}

vector<Student_info> classify_students(vector<Student_info>& students,
                                bool classifier(const Student_info&))
{
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), classifier);
    vector<Student_info> failed(iter, students.end());
    students.erase(iter, students.end());
    
    return failed;
}

bool did_all_homework(const Student_info& s)
{
    return ((std::find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}
bool fgrade(const Student_info& s)
{
    return s.grade() < 60;
}
bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}
