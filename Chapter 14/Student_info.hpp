#ifndef Student_handle_hpp
#define Student_handle_hpp
//
//  Student_handle.hpp
//  
//
//  Created by Stephen King on 12/3/17.
//
//

#include <iostream>
#include <stdexcept>
#include "Student_info.hpp"
//#include "Grad.cpp"

class Student_handle {
    
public:
    // Constructors and copy control
    Student_handle(): student(0) { }
    Student_handle(std::istream& in): student(0) { read(in); }
    Student_handle(const Student_handle&);
    Student_handle& operator=(const Student_handle&);
    ~Student_handle() { delete student; }
    
    // Operations
    std::istream& read(std::istream&);
    std::string name() const {
        if (student) return student->name();
        else throw std::runtime_error("Uninitialized Student");
    }
    
    double grade() const {
        if (student) return student->grade();
        else throw std::runtime_error("Uninitialized Student");
    }
    
    static bool compare(const Student_handle& s1, const Student_handle& s2) {
        return s1.name() < s2.name();
    }
    
private:
    Student_info* student;
   

};

#endif /* Student_handle_hpp */
