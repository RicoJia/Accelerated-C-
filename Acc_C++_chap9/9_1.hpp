//
//  9_1.hpp
//  9_funcs
//
//  Created by LOGIN on 2019-07-23.
//  Copyright © 2019 LOGIN. All rights reserved.
//

#ifndef __1_hpp
#define __1_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

int test_9_1();

class student_info
{
public:
    student_info():midterm(0),final(0),final_grade(0){}
    student_info(std::istream& in){input_info(in);}           // In case you want to create objects like this
    std::string name()const {return nombre;}
    double get_grade() const{return final_grade;}
    bool empty_hw(){return (homework.empty())?true:false;}
    std::istream& input_info(std::istream& in);
    
private:
    std::string nombre;
    double midterm, final,final_grade;
    std::vector<double> homework;
    double median(std::vector<double> vec)const;
    double grade()const;       // No need for wrapper for grade
    std::istream& read_hw(std::istream& in);    //get in into hw
    void clear(){nombre= ""; midterm = 0; final = 0; homework.clear();}
};

bool compare (const student_info& a, const student_info& b);

#endif /* __1_hpp */
