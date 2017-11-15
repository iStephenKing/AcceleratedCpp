#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include "average.h"
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
Student_infos classify_students(Student_infos& students,
                                bool classifier(const Student_info&));




template <class Function>
double analysis(const std::vector<Student_info>& students, Function gradingFunction)
{
    std::vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), gradingFunction);
        
    return median(grades);
}

template <class Function>
void write_analysis(std::ostream& out, const std::string& name,
                    Function gradingFunction,
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did, gradingFunction)
        << ", median(didnt) = " << analysis(didnt, gradingFunction) << std::endl;
}




#endif