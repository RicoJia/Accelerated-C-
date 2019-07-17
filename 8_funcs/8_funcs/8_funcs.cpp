// TODO: git hub: https://learn.adafruit.com/assets/26343
// then use git commit -f "initial commit" to force commit instead of git commit -f "initial commit"??
//  8_funcs.cpp
//  8_funcs
//
//  Created by LOGIN on 2019-07-15.
//  Copyright © 2019 LOGIN. All rights reserved.
//
#include <iostream>
#include <vector>
#include "8_funcs.hpp"
#include <iterator>

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

void test_remove()
{
    int p[] = {1,2,3,4};
    vector<double> l(7);
    copy_algo(p, p+4, l.begin());
    vector<double> l2 (l.begin(),remove_algo(l.begin(), l.end(), 2));
    print_vec<double>(l2);
}

void test_transform()
{
    int p[] = {1,2,3,4};
    vector<double> l(7);
    transform_algo(p, p+4, l.begin(), comp_remove_cope_if<int*>);
    print_vec<double>(l);
}

bool increment(double a)
{
    return (a>2)?true:false;
}

void test_accumulate()
{
    int p[] = {1,2,3,4};
    cout<<accumulate_algo(p, p+4, 3.0);
}

void test_search()
{
    int p[] = {1,2,3,4};
    vector<int> q1={3,4}, q2= {3,4,5}, q3;
    cout<<*search_algo(p, p+4, q1.begin(), q1.end())<<endl<<
    *search_algo(p, p+4, q2.begin(), q2.end())<<endl<<
    *search_algo(p, p+4, q3.begin(), q3.end())<<endl;
}

void test_find_if()
{
    cout<<"what number do you want to search in the secret Schrodinger Array?"<<endl;
    int num;
    cin>>num;
    int p[] = {1,2,3,4};
    cout<<*find_if_algo(std::begin(p), std::end(p), find_ur_num(num));
}

void test_partition()
{
    cout<<"what number do you want to set as partition (not included ) in the secret Schrodinger Array?"<<endl;
    int num;
    cin>>num;
    vector<int>d = {1,2,6,7,8,3,4,5};
    partition_algo(d.begin(), d.end(), less_than_ur_num(num));
    print_vec(d);
}
