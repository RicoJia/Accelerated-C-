//
// Created by rico on 7/23/19

#include "9_1.hpp"
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
#include <iomanip>      //setprecision.
using std::setprecision;
using std::setw;
#include <stdexcept>
using std::domain_error;
#include <cctype>       //isspace

int test_9_1()
{
    list<student_info> student_list;
    string::size_type max_len = 0;
    student_info stu;
    while(stu.input_info(cin))      //when input is not complete, stu will not be complete while cin will generate an error flag. and the list will not be added.
    {
        if(!cin) cout<<"cin is not cleared!"<<endl;
        max_len = max(max_len,stu.name().size());
                     if(!cin) cout<<"cin is not cleared!"<<endl;
        student_list.push_back(stu);
                     if(!cin) cout<<"cin is not cleared!"<<endl;
    }
    cin.clear();        //clear cin so it can be used in the future.
    
    student_list.sort(compare);
    for (auto i = student_list.begin(); i!=student_list.end();++i)
    {
            streamsize prec = cout.precision();
            cout<<std::left<<setw(max_len+1)<<i->name()<<": the final grade is "<<setprecision(3)<<i->get_grade()<<setprecision(prec)<<endl;
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

istream& student_info::input_info(istream& in)
{
    cout<<"Hello, please enter your name here"<<endl;
    getline(in,nombre);
//    if(!in) return in;      //TODO: future improvement: once an empty input is typed in, program exits!
    cout<<"Hi "<<nombre<<", please enter your midterm and final grades here"<<endl;
    in>>midterm>>final;
//    if(!in) return in;
    
    cout<<"Please enter all your homework values here, closed by ctrl+d"<<endl;
    read_hw(in);    //might be empty,end-of-file, return the status of reading cin, and write cin into homework.
    try{
        final_grade=grade();
    }
    catch (domain_error e){
        final_grade =  0.2*midterm+0.4*final;
        cout<<e.what();
    }
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






