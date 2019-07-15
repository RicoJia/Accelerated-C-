//
//  8_funcs.cpp
//  8_funcs
//
//  Created by LOGIN on 2019-07-15.
//  Copyright © 2019 LOGIN. All rights reserved.
//
#include <iostream>
#include <vector>
#include "8_funcs.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

template<typename T> void print_vec(const vector<T>& a)
{
    for (auto i = a.begin(); i!=a.end();++i)
        cout<<*i<<endl;
}
void test_equal()
{
    int p[] = {1,2,3,4};
    int q[] = {1,2,3,4,5};
    cout<<equal_algo(p, p+4, q);
}

void test_find()
{
    int p[] = {1,2,3,4};
    cout<<(bool)find_algo(p, p+4, 6);
}

void test_copy()
{
    int p[] = {1,2,3,4};
    vector<double> l(100);           
    copy_algo(p, p+4, l.begin());
    cout<<l[1];
}

void test_remove_copy_if()
{
    int p[] = {3,4,5,6};
    vector<double> l(7);          //vector automatically initializes to 0? Yes! pointer can be zero-initialized to 0 too. 
    remove_copy_if_algo(p, p+4, l.begin(), comp_remove_cope_if);
    print_vec<double>(l);
}
