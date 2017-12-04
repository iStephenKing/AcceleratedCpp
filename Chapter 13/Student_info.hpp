#ifndef GUARD_Student_info_hpp
#define GUARD_Student_info_hpp
/*
    From Accellerated C++

    Student_info.hpp
    Stephen King
    11/13/17
*/

#include <iostream>
#include <string>
#include <vector>
//#include "Student_handle.hpp"


class Student_info {
    
    friend bool did_all_homework(const Student_info& s);
    friend class Student_handle;
public:
    
    Student_info(): midterm(0), final(0) { }
    Student_info(std::istream& in) { read (in); }
    virtual ~Student_info() { }
    
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
    std::string letter_grade() const;
    std::string name() const{ return n;}
    bool valid() const{ return !homework.empty(); }

    
protected:
    virtual Student_info* clone() { return new Student_info(*this); }
    
    double midterm, final;
    std::vector<double> homework;
    std::istream& read_common(std::istream&);
    std::istream& read_hw(std::istream& in);
    
private:
    std::string n;

};

bool compare(const Student_info& x, const Student_info& y);
bool compare_ptrs(const Student_info* student1, const Student_info* student2);
bool compare_grades(const Student_info&, const Student_info&);
std::vector<Student_info> classify_students(std::vector<Student_info>& students,
                                    bool classifier(const Student_info&));

bool fgrade(const Student_info& s);
bool pgrade(const Student_info& s);



#endif