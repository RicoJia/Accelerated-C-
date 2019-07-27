//
// Created by rico on 7/24/19.
//

//
// Created by rico on 7/23/19

#include "9_5.h"
#include <string>
using std::string;
#include <iostream>
using std::istream;
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

int test_9_5()
{
    list<student_info> student_list;
    string::size_type max_len = 0;
    student_info stu;
    while(stu.input_grade(cin))      //when input is not complete, stu will not be complete while cin will generate an error flag. and the list will not be added.
    {
        max_len = max(max_len,stu.name().size());
        student_list.push_back(stu);
    }
    cin.clear();        //clear cin so it can be used in the future.

    list<student_info>::iterator fail_iter = partition(student_list.begin(),student_list.end(),student_info::F2front);//9_6: separate the lists first as time complexity of sort will be n*log(n/2)
    list <student_info> fail_list(student_list.begin(),fail_iter); list <student_info> pass_list(fail_iter,student_list.end());
    fail_list.sort(compare); pass_list.sort(compare);

    cout<<"Pass list: "<<endl;
    for (auto i = pass_list.begin(); i!=pass_list.end();++i)
    {
        streamsize prec = cout.precision();
        cout<<std::left<<setw(max_len+1)<<i->name()<<": the final grade is "<<setprecision(3)<<i->get_grade()<<setprecision(prec)
        <<"      P/F status: "<<i->get_letter_grade()<<endl;
    }

    cout<<"Fail list: "<<endl;
    for (auto i = fail_list.begin(); i!=fail_list.end();++i)
    {
        streamsize prec = cout.precision();
        cout<<std::left<<setw(max_len+1)<<i->name()<<": the final grade is "<<setprecision(3)<<i->get_grade()<<setprecision(prec)
            <<"      P/F status: "<<i->get_letter_grade()<<endl;
    }
    return 0;
}


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
    cout<<"Hello, please enter your name here"<<endl;
    getline(in,nombre);
    if(!in) return in;      //TODO: future improvement: once an empty input is typed in, program exits!
    cout<<"Hi "<<nombre<<", please enter your midterm and final grades here"<<endl;
    in>>midterm>>final;
    if(!in) return in;

    cout<<"Please enter all your homework values here, closed by ctrl+d"<<endl;
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
        while(in>>input)
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

