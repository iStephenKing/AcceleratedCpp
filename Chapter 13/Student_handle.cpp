//
//  Student_handle.cpp
//  
//
//  Created by Stephen King on 12/3/17.
//
//

#include "Student_handle.hpp"
#include "Student_info.hpp"
#include "Grad.hpp"

// Costructors and Copy Control
Student_handle::Student_handle(const Student_handle& s)
{
    if(s.student) student = s.student->clone();
}

Student_handle& Student_handle::operator=(const Student_handle& s)
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
std::istream& Student_handle::read(std::istream& in)
{
    delete student;
    
    char identifier;
    
    in >> identifier;
    
    if (identifier == 'U')
        student = new Student_info(in);
    else
        student = new Grad(in);
    
    
    return in;
}