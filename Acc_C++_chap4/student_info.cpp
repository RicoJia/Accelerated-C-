//
// Created by rico on 5/27/19.
//
#include "student_info.h"

#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include <iomanip>      //setprecision.
#include <ios>
#include <algorithm>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::streamsize;      //这个有点tricky
using std::istream;
using std::setprecision;
using std::sort;
using std::domain_error;
using std::max;             //这个也tricky

istream& read_hw(vector<double>& hw,istream& in)    //get in into hw
{
    if(in) 		//check in's status is good. if it's already corrupted, we will pass it along.
    {
        hw.clear(); // clear the vector if it has anything.
        double input = 0;
        while(in>>input)
        {
            hw.push_back(input);
        }
        in.clear(); // clear any state that indicates failure in reading. finishing cin will change the status of cin to error?? End-of-file is considered as an error and if there are errors incurred in the input process, we need to clear so future cin will work properly.
    }
    return in;
}

istream& input_info(istream& in, student_info& student)
{
    cout<<"Hello, please enter your name here"<<endl;
    getline(in,student.name);
    if(!in) return in;      //return false so the outside while loop will stop.
    cout<<"Hi "<<student.name<<", please enter your midterm and final grades here"<<endl;
    double midterm,final;
    in>>student.midterm>>student.final;
    if(!in) return in;

    cout<<"Please enter all your homework values here, closed by end of file"<<endl;
    read_hw(student.homework,in);    //might be empty,end-of-file, return the status of reading cin, and write cin into homework.
    return in;
}