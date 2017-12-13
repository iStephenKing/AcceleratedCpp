#ifndef Student_info_hpp
#define Student_info_hpp
//
//  Student_info.hpp
//  
//
//  Created by Stephen King on 12/3/17.
//
//

#include <iostream>
#include <stdexcept>
#include "Student_core.hpp"
//#include "Grad.cpp"

class Student_info {
    
public:
    // Constructors and copy control
    Student_info(): student(0) { }
    Student_info(std::istream& in): student(0) { read(in); }
    Student_info(const Student_info&);
    Student_info& operator=(const Student_info&);
    ~Student_info() { delete student; }
    
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
    
    static bool compare(const Student_info& s1, const Student_info& s2) {
        return s1.name() < s2.name();
    }
    
private:
    Student_core* student;
   

};

#endif /* Student_info_hpp */
