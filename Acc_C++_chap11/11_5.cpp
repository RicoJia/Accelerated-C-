//
// Created by rico on 7/26/19.
//
#include "11_5.h"
#include "chap11_vec.h"
#include <string>
using std::string;
#include <iostream>
using std::istream;
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <list>
using std::list;

int test_11_5()
{
    list<student_info> student_list_ls;
    vector<student_info> student_list_vector;
    vec<student_info> student_list_vec;
    generic_test_11_5(student_list_vector,"students1000.txt","vector");
    generic_test_11_5(student_list_vec,"students1000.txt","vec");
    return 0;
}


