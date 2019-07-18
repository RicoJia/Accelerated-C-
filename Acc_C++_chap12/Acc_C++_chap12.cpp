//
// Created by rico on 6/26/19.
//
#include "12_textbook.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
    Str a = "lol";
    cin>>a;
    cout<<a[0]<<endl;
    a[0] = 'p';
    cout<<a<<endl;
    Str b = "sos";
    Str c = "sos"+a;
    cout<<c<<endl;
    string d = "lol"+"s";
    return 0;
}
