//
// Created by rico on 6/14/19.
//
#include "chap10_funcs.h"
#include <iostream>
//#include <cstring>
#include <string>
#include <cstddef>
#include <fstream>
#include <vector>
#include <list>

using std::cin;
using std::cout;
using std::cerr;
using std::clog;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
using std::ofstream;
using std::list;
using std::istream;

int main(int argc,char**argv)
{
    // this file implements a vec class that 1. vec(), vec(2),vec(2,'b') 2.vec1 = vec 2  3. vec[n] r/w 4. return begin, end 5. push_back
/*vec<int> v(5,100);
vec<int> v2;
v2 = v;

v2[4] = 1000;


v2.push_back(10000);
cout<<v2.size()<<endl<<endl;
for (auto i = 0;i!=v2.size();++i)
{cout<<v2[i]<<endl;}*/
ifstream in("sample_in.txt");
string s;
getline(in,s);
cout<<s;

return 0;
}
