//
// Created by rico on 6/26/19.
//

#include "12_textbook.h"
#include <iostream>
#include <cctype>

using std::vector;
using std::istream;
using std::ostream;
using std::cout;

istream& operator>> (istream& in,Str& s)
{
    s.data.clear();
    char c;
    while(in.get(c)&&isspace(c));
    do{
        s.data.push_back(c);

    }while(in.get(c)&&!isspace(c));
    in.unget();
    return in;
}

ostream& operator<< (ostream& out,Str& s)
{
    for(auto i=s.data.begin();i!=s.data.end();++i)
    {
        out<<*i;
    }
    return out;
}

Str operator+ (const Str& a, const Str& b)  //it can't be Str& since the object will be destroyed
{
    Str r = a;
    return r+=b;
}