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

class Student_info {
public:
    Student_info();
    Student_info(std::istream& in);
    std::istream& read(std::istream&);
    double grade() const;
    std::string name() const { return n;}
    bool valid() const { return !homework.empty(); }
    bool did_all_homework() const { return ((find(homework.begin(), homework.end(), 0)) == homework.end()); }
    bool fgrade() const { return grade() < 60; }
    bool pgrade() const { return !fgrade(); }
    
private:
    double g;
    std::string n;
    double midterm, final;
    std::vector<double> homework;
    std::istream& read_hw(std::istream& in, std::vector<double>& hw);

};

bool compare(const Student_info& x, const Student_info& y);



#endif