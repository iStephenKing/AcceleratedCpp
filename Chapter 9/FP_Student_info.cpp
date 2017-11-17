/*
    From Acellerated C++
 
    Student_info.cpp
    Stephen King
    11/17/17
 */

#include "FP_Student_info.h"
#include <algorithm>

using std::istream; using std::vector; using std::endl;

FP_Student_info::FP_Student_info(): midterm(0), final(0) {}

FP_Student_info::FP_Student_info(std::istream& in)
{
    read (in);
}

// Predicate used to sort Students
bool compare(const FP_Student_info& x, const FP_Student_info& y)
{
    return x.name() < y.name();
}

// Student info member function
// read in name, grades
istream& FP_Student_info::read(istream& in)
{
    in >> n >> midterm >> final;

    return in;
}

char FP_Student_info::grade() const
{
    return (0.33 * midterm + 0.67 * final) > 60 ? 'P' : 'F';
}

