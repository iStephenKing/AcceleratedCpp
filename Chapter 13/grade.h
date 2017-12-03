#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include "average.h"
#include "Vec.h"
#include <list>


double grade(double midterm, double final, const Vec<double>& hw, double average(Vec<double>) = median);
double grade(double midterm, double final, double homework);



#endif