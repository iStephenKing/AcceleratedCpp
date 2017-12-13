#ifndef GRAD_HPP
#define GRAD_HPP
/*

    From Accelerated C++
    By Andrew Koenig and Barbara E. Moo
 
    Grad inherits from Student_core
    Grad students must complete a thesis 
    in addition to functioning as a student
 
    Stephen King
    12/02/17
 */

#include "Student_core.hpp"

class Grad : public Student_core {
    
public:
    Grad(): thesis(0) { }
    Grad(std::istream& is) { }
    double grade() const;
    void regrade(double d1, double d2) { final = d1; thesis = d2; }
    std::istream& read(std::istream&);
    
    bool valid() const{ return Student_core::valid() && thesis >= 0 && thesis <= 100; }  // Homework must be non empty and thesis must be initialized
    
protected:
    Grad* clone() { return new Grad(*this); }
    
private:
    double thesis;
    
    
};

#endif
 