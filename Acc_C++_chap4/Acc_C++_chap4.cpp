//
// Created by rico on 5/23/19.
//
#include <iostream>
#include <ios>
#include <list>
#include <string>
#include <iomanip>      //setprecision.
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "student_info.h"
#

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::string;
using std::streamsize;      //这个有点tricky
using std::istream;
using std::setprecision;
using std::sort;
using std::domain_error;
using std::max;             //这个也tricky
using std::setw;

// input student name, record
// put the names in lists
// output names in the same length
// calculate grade and output in 3 significant digits


int main()
{
    list<student_info> student_list;
    string::size_type max_len = 0;
    student_info stu;
    while(input_info(cin,stu))      //when input is not complete, stu will not be complete while cin will generate an error flag. and the list will not be added.
    {
        max_len = max(max_len,stu.name.size());
        student_list.push_back(stu);
        }
    cin.clear();        //clear cin so it can be used in the future.

    student_list.sort(compare);
    list<student_info>::size_type size = student_list.size();
    for (auto i = student_list.begin(); i!=student_list.end();++i)
    {
        try {
            double final_grade = grade(i->midterm,i->final,i->homework);
            streamsize prec = cout.precision();
            cout<<setw(max_len+1)<<i->name<<": the final grade is "<<setprecision(3)<<final_grade<<setprecision(prec)<<endl;
        }
        catch (domain_error e){
            cout<<e.what();
            return 1;           //DON"T FORGET THIS RETURN 1
        }
    }

    return 0;

}


