#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include "average.h"
#include <vector>
#include <list>

typedef std::vector<Student_info> Student_infos;

double grade(double midterm, double final, const std::vector<double>& hw, double average(std::vector<double>) = median);
//double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double homework);



#endif