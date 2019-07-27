//
// Created by rico on 7/26/19.
//

#ifndef ACCELERATED_C_CHAP11_STUDENT_INFO_H
#define ACCELERATED_C_CHAP11_STUDENT_INFO_H

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <list>

class student_info
{
public:
    student_info():midterm(0),final(0),final_grade(0),letter_grade('N'){++default_const_call;}
    student_info(std::istream& in){input_grade(in);++stream_const_call;}           // In case you want to create objects like this
    student_info(const student_info& stu){
        ++copy_const_call;
        midterm = stu.midterm;final = stu.final;final_grade = stu.final_grade;letter_grade = stu.letter_grade;homework = stu.homework;
    }
    student_info& operator= (const student_info& stu){
        ++assignment_call;
        if(&stu!=this)
        {midterm = stu.midterm;final = stu.final;final_grade = stu.final_grade;letter_grade = stu.letter_grade;homework = stu.homework;}
        return *this;
    }
    std::string name()const {return nombre;}
    double get_grade() const{return final_grade;}
    char get_letter_grade() const {return letter_grade;}
    bool empty_hw(){return (homework.empty())?true:false;}
    std::istream& input_grade(std::istream& in);
    static bool F2front (student_info& stu);
    ~student_info(){
        ++destruct_call;}

    static std::ostream& print_call(std::ostream&);
    static void reset_call();

private:
    std::string nombre;
    double midterm, final,final_grade;
    char letter_grade;
    std::vector<double> homework;
    double median(std::vector<double> vec)const;
    double grade()const;       // No need for wrapper for grade
    std::istream& read_hw(std::istream& in);    //get in into hw
    void clear(){nombre= ""; midterm = 0; final = 0; homework.clear();}

    static int default_const_call,copy_const_call,destruct_call,assignment_call,stream_const_call;
};

bool compare (const student_info& a, const student_info& b);

#endif //ACCELERATED_C_CHAP11_STUDENT_INFO_H
