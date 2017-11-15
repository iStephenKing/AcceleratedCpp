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

// Calculates a students grade using the mean of the homework grades
double mean_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, mean(s.homework));
}

// Calculates a studnets grade using median of only homework submitted
double optimistic_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, optimistic_median(s.homework));
}

// Helper function to catch domain error thrown by median
double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

// Determines if a Student has fail
bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}

bool did_all_hw(const Student_info& s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0))
            == s.homework.end());
}


Student_infos classify_students(Student_infos& students,
                                bool classifier(const Student_info&))
{
    Student_infos::iterator iter = stable_partition(students.begin(), students.end(), classifier);
    Student_infos failed(iter, students.end());
    students.erase(iter, students.end());
    
    return failed;
}

