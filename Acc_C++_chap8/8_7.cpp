//
// Created by rico on 7/19/19.
//

#include "8_7.h"
#include <iostream>

using namespace std;

template <typename T, typename V, typename TV>
TV max(const T& a, const V& b)
{
    return (a>=b)?a:b;
}

//You don't use two different types is because you need to use a 3rd type and specify it.
void test_8_7()
{
    cout<<max<int,double,int>(4.9,1.5);
}
