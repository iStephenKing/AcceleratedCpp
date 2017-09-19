#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include <vector>
#include <list>

typedef std::vector<Student_info> Student_infos;

double grade(const Student_info& s);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double homework);
double grade_aux(const Student_info& s);
double mean_grade(const Student_info& s);
double optimistic_grade(const Student_info& s);
bool fgrade(const Student_info& s);
bool pgrade(const Student_info& s);
bool did_all_hw(const Student_info& s);
Student_infos extract_fails(Student_infos& students);
Student_infos extract_slackers(Student_infos& students);
void write_analysis(std::ostream& out, const std::string& name,
                    double grader(const Student_info&),
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt);
double median_analysis(const std::vector<Student_info>& students);
double mean_analysis(const std::vector<Student_info>& students);
double optimistic_analysis(const std::vector<Student_info>& students);
double analysis(const std::vector<Student_info>& students,
                double grader(const Student_info&));




#endif