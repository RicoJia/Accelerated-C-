//
// Created by rico on 6/11/19.
//

#ifndef C_EXAMPLES_CHAP6_STUDENT_INFO_FUNC_H
#define C_EXAMPLES_CHAP6_STUDENT_INFO_FUNC_H

#define passing_grade 50

#include <iostream>
#include <vector>
#include <string>
#include <list>

class student
{
private:
    std::string name;
    double mt,fn;
    std::vector<double> hw;
    double true_grade();

public:
    std::istream& read_grades(std::istream& in);
    std::string get_name(){return name;}
    std::vector<double>::size_type hw_size_check(){return hw.size();}
    student():mt(0),fn(0){}

    double grade();
    void pad_0(std::vector<double>::size_type);
};

double grade_aux(student&);

bool name_cmp(student&, student&);
bool did_all_hw(std::vector<double>::size_type,std::vector<double>::size_type);
void write_analysis(std::ostream& out, std::string name_analysis, double analysis(std::list<student>&),std::list<student>&, std::list<student>&);
double median_analysis(std::list<student>&);
double find_median(std::vector<double>);

bool pgrade(double);
#endif //C_EXAMPLES_CHAP6_STUDENT_INFO_FUNC_H
