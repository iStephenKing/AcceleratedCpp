#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_core.hpp"
#include "average.h"
#include <vector>


double grade(double midterm, double final, const std::vector<double>& hw, double average(std::vector<double>) = median);
double grade(double midterm, double final, double homework);



#endif