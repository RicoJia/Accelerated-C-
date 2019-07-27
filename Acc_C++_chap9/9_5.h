//
// Created by rico on 7/24/19.
/*
 * Readme: 9_5 has below features:
 * 1. grading students and give P/F (passing standard is 60)
 * 2. if homework is empty, then homework is zero.
 * 3. Print report alphabetically
 * 4. (9_6), print passing, failing students separately and alphabetically
 */
//

#ifndef ACCELERATED_C_9_5_H
#define ACCELERATED_C_9_5_H
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <list>

int test_9_5();         //TODO: how this is used in the program?

class student_info
{
public:
    student_info():midterm(0),final(0),final_grade(0),letter_grade('N'){}
    student_info(std::istream& in){input_grade(in);}           // In case you want to create objects like this
    std::string name()const {return nombre;}
    double get_grade() const{return final_grade;}
    char get_letter_grade() const {return letter_grade;}
    bool empty_hw(){return (homework.empty())?true:false;}
    std::istream& input_grade(std::istream& in);
    static bool F2front (student_info& stu);

private:
    std::string nombre;
    double midterm, final,final_grade;
    char letter_grade;
    std::vector<double> homework;
    double median(std::vector<double> vec)const;
    double grade()const;       // No need for wrapper for grade
    std::istream& read_hw(std::istream& in);    //get in into hw
    void clear(){nombre= ""; midterm = 0; final = 0; homework.clear();}
};

bool compare (const student_info& a, const student_info& b);

#endif //ACCELERATED_C_9_5_H
