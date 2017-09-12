#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include <vector>
#include <list>

typedef std::vector<Student_info> Student_infos;

double grade(const Student_info& s);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double homework);
double mean_grade(const Student_info& s);
double optimistic_grade(const Student_info& s);
bool fgrade(const Student_info& s);
bool pgrade(const Student_info& s);
Student_infos extract_fails(Student_infos& students);
void write_analysis(std::ostream& out, const std::string& name,
                    double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt);
double median_analysis(const std::vector<Student_info>& students);
double mean_analysis(const std::vector<Student_info>& students);
double optimistic_analysis(const std::vector<Student_info>& students);




#endif