/*
    From Acellerated C++
 
    Student_info.cpp
    Stephen King
    8/12/17
 */

#include "Student_info.h"
#include "grade.h"
#include <algorithm>

using std::istream; using std::vector; using std::endl;

Student_info::Student_info(): midterm(0), final(0) {}

Student_info::Student_info(std::istream& in)
{
    read (in);
}

// Predicate used to sort Students
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}

// Student info member function
// read in name, grades
istream& Student_info::read(istream& in)
{
    in >> n >> midterm >> final;
    
    read_hw(in, homework);

    return in;
}

double Student_info::grade() const
{
    return ::grade(midterm, final, homework);
}

// Read homework grades into hw vector
istream& Student_info::read_hw(istream& in, vector<double>& hw)
{
    // use input stream to read grades into hw
    if (in) {
        // Empty Vector of any previous results
        hw.clear();
        
        // Read homework grades until EOF or invalid data
        double x;
        while (in >> std::dec >> x)
            hw.push_back(x);
        
        // Clear Error state for next read attempt
        in.clear();
    }
    
    return in;
}
