//
// Created by rico on 6/30/19.
//

#include "13_textbook.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int& test(int* k)
{
    return *k;
}
int main()
{
    //student_info_13();
    int j = 0;
    int *i = &j;
    int& k = test(i);
    k = 10;
    cout<<j;
    grad c1;
    return 0;
}