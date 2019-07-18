//
// Created by rico on 5/27/19.
//

#ifndef C_EXAMPLES_STUDENT_INFO_H
#define C_EXAMPLES_STUDENT_INFO_H

#include <vector>
#include <string>
#include <iostream>

struct student_info
{
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};   //this has to be replaced before all other definitions, since they might use this!

std::istream& read_hw(std::vector<double>& hw,std::istream& in);
std::istream& input_info(std::istream& in, student_info& student);
#endif //C_EXAMPLES_STUDENT_INFO_H
