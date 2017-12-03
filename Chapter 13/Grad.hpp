#ifndef GRAD_HPP
#define GRAD_HPP
/*

    From Accelerated C++
    By Andrew Koenig and Barbara E. Moo
 
    Grad inherits from Student_info
    Grad students must complete a thesis 
    in addition to functioning as a student
 
    Stephen King
    12/02/17
 */

#include "Student_info.hpp"

class Grad : public Student_info {
    
public:
    Grad(): thesis(0) { }
    Grad(std::istream& is) { read(is); }
    double grade() const;
    std::istream& read(std::istream&);
private:
    double thesis;
    
    
};

#endif
 