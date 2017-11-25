#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h
/*
    From Accellerated C++

    Student_info.h
    Stephen King
    11/13/17
*/

#include <iostream>
#include <string>
#include "Vec.h"


class Student_info {
public:
    std::string name;
    double midterm, final;
    Vec<double> homework;
    
    Student_info();
    Student_info(const Student_info& other);
    Student_info& operator=(const Student_info& rhs);
    ~Student_info();
    
    std::istream& read(std::istream&);
    double grade() const;
    std::string letter_grade() const;
    //std::string name() const{ return n;}
    bool valid() const{ return !homework.empty(); }

    
private:
    //std::string n;
    //double midterm, final;
    //std::vector<double> homework;
    std::istream& read_hw(std::istream& in, Vec<double>& hw);

};

bool compare(const Student_info& x, const Student_info& y);
Vec<Student_info> classify_students(Vec<Student_info>& students,
                                    bool classifier(const Student_info&));
bool did_all_homework(const Student_info& s);
bool fgrade(const Student_info& s);
bool pgrade(const Student_info& s);



#endif