//
// Created by rico on 6/21/19.
//
#include "chap11_vec.h"
#include "chap11_student_info.h"
#include <iostream>
#include <cstddef>
using std::endl; using std::cout;
int test_vec()
{
    //initialization tests
    vec<int> a = {9,8};
    vec<int> b(4,6);
    vec<int> c (b.begin(),b.end());
    vec<int> d(b);
    const vec<int> e = a;         // implicit conversion
    //operator test
    c = a;
    a[1] = 100;
    a= {100, 120};       //implicit conversion from temp obj
    //utility test
    c.clear();
    b. push_back(3);
    cout<<"---------------"<<endl<<e.size()<<endl;

    student_info stu;
    vec<student_info> s = {stu};
    s.push_back(stu);
    //print
    print_vec<int>(a);
    print_vec<int>(b);
    print_vec<int>(c);
    print_vec<int>(d);
    print_vec<int>(e);
    print_vec<int>(c);
    print_vec<int>(e);

    return 0;
}

//-----------------------------------------------------------------------------------------
