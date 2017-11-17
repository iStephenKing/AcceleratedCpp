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
#include <vector>


class FP_Student_info {
public:
    FP_Student_info();
    FP_Student_info(std::istream& in);
    std::istream& read(std::istream&);
    char lettergrade() const;
    std::string name() const{ return n;}

    bool fgrade() const{ return grade() < 60; }
    bool pgrade() const{ return !fgrade(); }
    
private:
    std::string n;
    double midterm, final;
    double grade() const;
};

bool compare(const FP_Student_info& x, const FP_Student_info& y);



#endif