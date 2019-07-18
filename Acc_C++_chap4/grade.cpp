//
// Created by rico on 5/27/19.
//
#include "grade.h"
#include "median.h"
#include <vector>
#include <stdexcept>


using std::vector;
using std::domain_error;


double grade(double mt, double fn, const vector<double>& hw)    //This is a wrapper for grade
{
    if(hw.empty())
        throw domain_error("the student has no homework");
    return grade(mt,fn,median(hw));
}
inline double grade(double mt, double fn, double hw)
{
    return 0.2*mt+0.4*fn+0.4*hw;
}


bool compare (const student_info& a, const student_info& b)
{
    return a.name<b.name;
}

