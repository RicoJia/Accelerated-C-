//
// Created by rico on 7/26/19.
//

#include "chap11_student_info.h"
#include <string>
using std::string;
#include <iostream>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
#include <ios>
using std::streamsize;
using std::left;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <algorithm>
using std::sort;
using std::max;
using std::partition;
#include <iomanip>      //setprecision.
using std::setprecision;
using std::setw;
#include <stdexcept>
using std::domain_error;
using std::exception;
#include <cctype>       //isspace

int student_info::default_const_call;
int student_info::stream_const_call;
int student_info::copy_const_call;
int student_info::assignment_call;
int student_info::destruct_call;

double student_info::median (std::vector<double> vec) const
{
    typedef vector<double>::size_type vectorsz;
    vectorsz size = vec.size();
    if (size == 0)
        throw domain_error("Peligroso!");
    sort(vec.begin(),vec.end());
    return (size%2)?(vec[size/2]+vec[size/2-1])/2:vec[size/2];
}

double student_info::grade () const   //This is a wrapper for grade
{
    if(homework.empty())
        throw domain_error("the student has no homework");
    return 0.2*midterm+0.4*final+0.4*median(homework);
}

bool compare (const student_info& a, const student_info& b)
{
    return a.name()<b.name();
}

istream& student_info::input_grade(istream& in)
{
    in>>nombre;
    if(!in) return in;      //TODO: future improvement: once an empty input is typed in, program exits!
    in>>midterm>>final;
    if(!in) return in;
    read_hw(in);    //might be empty,end-of-file, return the status of reading cin, and write cin into homework.
    try{
        final_grade=grade();
    }
    catch (exception& e){
        final_grade =  0.2*midterm+0.4*final;
        cout<<e.what();             //notify the user that this student has no hw!. shows "std::exception"??
    }
    letter_grade = (final_grade>=60)?'P':'F';
    return in;
}

istream& student_info::read_hw(istream& in)
{
    if(in)         //check in's status is good. if it's already corrupted, we will pass it along.
    {
        homework.clear(); // clear the vector if it has anything.
        double input = 0;
        while(in>>input)            //TODO:status is true at newline?
        {
            homework.push_back(input);
        }
        in.clear(); // clear any state that indicates failure in reading. finishing cin will change the status of cin to error?? End-of-file is considered as an error and if there are errors incurred in the input process, we need to clear so future cin will work properly.
    }
    return in;
}


bool student_info::F2front (student_info& stu)
{
    return (stu.get_letter_grade()=='F');
}

//----------------Added utility funcs
ostream& student_info::print_call(ostream& out)
{
    out<<"+++++++++++++++++++++++++++"<<endl
    <<"Default Constructor called: "<<default_const_call<<endl
    <<"Stream Constructor called: "<<stream_const_call<<endl
    <<"Copy Constructor called: "<<copy_const_call<<endl
    <<"Assignment Operator called: "<<assignment_call<<endl
    <<"Destructor called: "<<destruct_call<<endl;
    return out;
}

void student_info::reset_call()
{
    default_const_call = 0;
    stream_const_call = 0;
    copy_const_call = 0;
    assignment_call = 0;
    destruct_call = 0;
}