/*
    From Accellerated C++

    grade.cpp
    Stephen King
    8/12/17
*/

#include "grade.h"
#include <stdexcept>
#include <vector>
#include "median.h"
#include "Student_info.h"

using std::vector; using std::domain_error;

// compute a students grade from midterm and final exam grades and homeword grades
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// Computes a students grades from midterm, final, and homework grades
// Passes a pointer (reference) to homework vector
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("Student has done no homework");
    return grade(midterm, final, median(hw));
}

// Calculates a students grades
double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

char letterGrade(const Student_info& s)
{
    double sgrade = grade(s);
    
    return sgrade >= 90 ? 'A' :
           sgrade >= 80 ? 'B' :
           sgrade >= 70 ? 'C' :
           sgrade >= 60 ? 'D' : 'F';
}