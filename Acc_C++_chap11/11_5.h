//
// Created by rico on 7/26/19.
/*
 * Readme: This file is to
 * 1. read large number of student records from txt files and grade them
 * 2. Separate passing and failing students.
 * 3. keep track of the # of objects being created
 * 4. keep track of the time for reading, and Separating
 */
//

#ifndef ACCELERATED_C_11_5_H
#define ACCELERATED_C_11_5_H

#include "chap11_student_info.h"
#include <string>
using std::string;
#include <iostream>
using std::istream;
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
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
#include <chrono>       // better precision
using std::chrono::system_clock;
#include <ctime>

int test_11_5();

template <typename T>
void generic_test_11_5(T& student_list, string file_name, string container_type)
{
    ifstream file(file_name);
    if(file)
    {
        student_info::reset_call();
        string::size_type max_len = 0;
        student_info stu;
        auto start = system_clock::now();
        while(stu.input_grade(file))      //when input is not complete, stu will not be complete while cin will generate an error flag. and the list will not be added.
        {
            max_len = max(max_len,stu.name().size());
            student_list.push_back(stu);
        }
        cin.clear();        //clear cin so it can be used in the future.

        auto read_end = system_clock::now();
        std::chrono::duration<double> elapsed_seconds = read_end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(read_end);
        cout<<"********************************"<<endl
            <<container_type<<" :"<<endl
            <<"Reading takes "<<elapsed_seconds.count()<<"s\n"
            <<"Now time is "<<std::ctime(&end_time)<<endl;

        auto fail_iter = partition(student_list.begin(),student_list.end(),student_info::F2front);//9_6: separate the lists first as time complexity of sort will be n*log(n/2)
        list <student_info> fail_list(student_list.begin(),fail_iter); list <student_info> pass_list(fail_iter,student_list.end());
        fail_list.sort(compare); pass_list.sort(compare);

        auto separation_end = system_clock::now();
        elapsed_seconds = separation_end-read_end;
        end_time = std::chrono::system_clock::to_time_t(separation_end);
        cout<<"---------"<<endl
            <<container_type<<" :"<<endl
            <<"Separation takes "<<elapsed_seconds.count()<<"s\n"
            <<"Now time is "<<std::ctime(&end_time)<<endl;

        elapsed_seconds = read_end-start;
        cout<<"---------"<<endl
            <<container_type<<" :"<<endl
            <<"In total it takes "<<elapsed_seconds.count()<<"s\n";

        student_info::print_call(cout);         //destructor calls are fewer than the actual number, since many are not expired at this step.
    }
    else
        cout<<"File Cannot Open: "<<file_name<<endl;
}
#endif //ACCELERATED_C_11_5_H
