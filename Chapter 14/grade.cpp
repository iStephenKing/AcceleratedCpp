/*
    From Accellerated C++

    grade.cpp
    Stephen King
    8/12/17
*/

#include <stdexcept>
#include <vector>
#include <algorithm>

#include "grade.h"
#include "average.h"
#include "Student_core.hpp"


using std::domain_error;

// compute a students grade from midterm and final exam grades and homeword grades
double grade(double midterm, double final, double homework)
{
    
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// Computes a students grades from midterm, final, and homework grades
// Passes a pointer (reference) to homework vector

double grade(double midterm, double final, const std::vector<double>& hw,double average(std::vector<double>))
{
    if (hw.size() == 0) {
        throw domain_error("Student has done no homework");
    }
    
    return grade(midterm, final, average(hw));
}


template <class T> double grade(double midterm, double final, const std::vector<T>& hw)
{
    return grade(midterm, final, hw.size() == 0 ? 0 : median(hw));
}


