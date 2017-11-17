/*
    From Accellerated C++

    grade.cpp
    Stephen King
    8/12/17
*/

#include <stdexcept>
#include <list>
#include <vector>
#include <algorithm>

#include "grade.h"
#include "average.h"
#include "Student_info.h"

using std::domain_error; using std::vector;

// compute a students grade from midterm and final exam grades and homeword grades
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// Computes a students grades from midterm, final, and homework grades
// Passes a pointer (reference) to homework vector
/*
double grade(double midterm, double final, const vector<double>& hw,double average(const std::vector<double>&))
{
    return grade(midterm, final, hw.size() == 0 ? 0 : average(hw));
}
 */

double grade(double midterm, double final, const vector<double>& hw)
{
    return grade(midterm, final, hw.size() == 0 ? 0 : median(hw));
}


