//
// Created by rico on 7/23/19.
/*
 * README: this file is the 2nd improvement on the student info system. Improvements include:
     * 1. Encapsulation of private data members. (Prevents undesired access/modifications to datamembers)
     * 2. Public Interface
     * 3. Empty entry prevention
 * Below are the basic design ideas
 * 1. an student_info object has default values, but their info will be asked for update.
 * Question: how to repeat reading a student's info? A: you don't use constructor, use a read function instead.
 */

#ifndef ACCELERATED_C_TEXTBOOK_H
#define ACCELERATED_C_TEXTBOOK_H

#include <string>
#include <vector>
#include <iostream>

int test_student_info();

class student_info
{
public:
    student_info():midterm(0),final(0){}
    student_info(std::istream& in){input_info(in);}           // In case you want to create objects like this
    std::string name()const {return nombre;}
    double grade()const;       // No need for wrapper for grade
    bool empty_hw(){return (homework.empty())?true:false;}
    std::istream& input_info(std::istream& in);

private:
    std::string nombre;
    double midterm, final;
    std::vector<double> homework;
    double median(std::vector<double> vec)const;
    std::istream& read_hw(std::istream& in);    //get in into hw
    void clear(){nombre= ""; midterm = 0; final = 0; homework.clear();}
};

bool compare (const student_info& a, const student_info& b);


#endif //ACCELERATED_C_TEXTBOOK_H
