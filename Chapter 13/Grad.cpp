/*
 
    From Accelerated C++
    By Andrew Koenig and Barbara E. Moo
 
    Grad inherits from Student_info
    Grad students must complete a thesis
    in addition to functioning as a student
 
    Stephen King
    12/02/17
 */

#include "Grad.hpp"
#include <algorithm>


double Grad::grade() const
{
    return std::min(Student_info::grade(), thesis);
    
}

std::istream& Grad::read(std::istream&in)
{
    read_common(in);
    in >> thesis;
    read_hw(in);
    
    return in;
}


    