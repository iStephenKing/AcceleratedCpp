/*
    From Acellerated C++
 
    Student_info.cpp
    Stephen King
    8/12/17
 */

#include "Student_info.h"
#include "grade.h"
#include <algorithm>
#include <iterator>

using namespace std;

Student_info::Student_info(): midterm(0), final(0)
{
    cout << "create" << endl;
}

Student_info::Student_info(const Student_info& other)
{
    cout << "copy" << endl;
    name = other.name;
    midterm = other.midterm;
    final = other.final;
    homework = other.homework;
}

/*
Student_info::Student_info(std::istream& in)
{
    cout << "create" << endl;
    read (in);
}
*/

Student_info& Student_info::operator=(const Student_info& other)
{
    cout << "assign" << endl;
    if (this != &other)
    {
        name = other.name;
        midterm = other.midterm;
        final = other.final;
        homework = other.homework;
    }
    return *this;
}

Student_info::~Student_info()
{
    cout << "destroy" << endl;
}

// Predicate used to sort Students
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

// Student info member function
// read in name, grades
istream& Student_info::read(istream& in)
{
    in >> name >> midterm >> final;
    
    read_hw(in, homework);

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

// Read homework grades into hw vector
istream& Student_info::read_hw(istream& in, Vec<double>& hw)
{
    // use input stream to read grades into hw
    if (in) {
        // Empty Vector of any previous results
        hw.clear();
        
        // Read homework grades until EOF or invalid data
        double x;
        while (in >> std::dec >> x)
            hw.push_back(x);
        
        // Clear Error state for next read attempt
        in.clear();
    }
    
    return in;
}

Vec<Student_info> classify_students(Vec<Student_info>& students,
                                bool classifier(const Student_info&))
{
    Vec<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), classifier);
    Vec<Student_info> failed(iter, students.end());
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
