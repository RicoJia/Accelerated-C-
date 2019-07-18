//
// Created by rico on 6/11/19.
//
#include "chap6_student_info_main.h"
#include "chap6_student_info_func.h"

#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::vector;

void chap_student_info_main()
{
    vector<double>::size_type hw_num;
    cout<<"Welcome to the homework management system!"<<endl
    <<"------------------------------------------"<<endl
    <<"how many assignments do you have? "<<endl;
    cin>>hw_num;

    student stu;
    list<student> good_students;
    list<student> bad_students;
    list<student> all_students;
    cin.ignore();
    while(stu.read_grades(cin))
    {
        if(did_all_hw(stu.hw_size_check(),hw_num))
            good_students.push_back(stu);
        else{
            stu.pad_0(hw_num);
            bad_students.push_back(stu);
        }
    }

    all_students.insert(all_students.end(),good_students.begin(),good_students.end());
    all_students.insert(all_students.end(),bad_students.begin(),bad_students.end());
    all_students.sort(name_cmp);

    if(good_students.empty()&&!bad_students.empty()) cout<<"NOBODY DID ALL HOMEWORK!!"<<endl;
    else if(!good_students.empty()&&bad_students.empty()) cout<<"EVERYONE DID THEIR HOMEWORK!"<<endl;
    else cout<<"SOME PPL DID THEIR HOMEWORK, SOME PPL DIDN'T"<<endl;

    cout<<"------------------------------------------"<<endl;
    write_analysis(cout,"median",median_analysis,good_students,bad_students);
}