//
//  Student_info.cpp
//  
//
//  Created by Stephen King on 12/3/17.
//
//

#include "Student_info.hpp"
#include "Student_core.hpp"
#include "Grad.hpp"

// Costructors and Copy Control
Student_info::Student_info(const Student_info& s)
{
    if(s.student) student = s.student->clone();
}

Student_info& Student_info::operator=(const Student_info& s)
{
    if (&s != this)
    {
        delete student;
        if (s.student) student = s.student->clone();
        else student = 0;
    }
    
    return *this;
}

// Operations
std::istream& Student_info::read(std::istream& in)
{
    delete student;
    
    char identifier;
    
    in >> identifier;
    
    if (identifier == 'U')
        student = new Student_core(in);
    else
        student = new Grad(in);
    
    
    return in;
}