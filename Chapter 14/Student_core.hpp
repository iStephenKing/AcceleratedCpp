#ifndef GUARD_Student_core_hpp
#define GUARD_Student_core_hpp
/*
    From Accellerated C++

    Student_core.hpp
    Stephen King
    11/13/17
*/

#include <iostream>
#include <string>
#include <vector>
#include "Handle.hpp"



class Student_core {
    
    friend bool did_all_homework(const Student_core& s);
    //friend class Student_info;
    friend class Handle<Student_core>;
public:
    
    Student_core(): midterm(0), final(0) { }
    Student_core(std::istream& in) { read (in); }
    virtual ~Student_core() { }
    
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
    virtual void regrade(double d1, double d2 = 0) { final = d1; }
    std::string letter_grade() const;
    std::string name() const{ return n; }
    virtual bool valid() const{ return !homework.empty(); }

    
protected:
    virtual Student_core* clone() { return new Student_core(*this); }
    
    double midterm, final;
    std::vector<double> homework;
    std::istream& read_common(std::istream&);
    std::istream& read_hw(std::istream& in);
    
private:
    std::string n;

};

bool compare(const Student_core& x, const Student_core& y);
bool compare_ptrs(const Student_core* student1, const Student_core* student2);
bool compare_grades(const Student_core&, const Student_core&);
std::vector<Student_core> classify_students(std::vector<Student_core>& students,
                                    bool classifier(const Student_core&));

bool fgrade(const Student_core& s);
bool pgrade(const Student_core& s);



#endif