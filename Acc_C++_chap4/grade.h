//
// Created by rico on 5/27/19.
//

#ifndef C_EXAMPLES_GRADE_H
#define C_EXAMPLES_GRADE_H
#include "median.h"
#include "student_info.h"
#include <vector>
#include <iostream>

double grade(double mt, double fn, const std::vector<double>& hw);
double grade(double mt, double fn, double hw);
bool compare (const student_info& a, const student_info& b);

#endif //C_EXAMPLES_GRADE_H
