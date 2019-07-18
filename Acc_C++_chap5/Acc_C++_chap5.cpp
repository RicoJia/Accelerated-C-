//
// Created by rico on 5/30/19.
//
#include <string>
#include <iostream>
#include <vector>
#include "split_print.h"
#include "frame_width.h"
#include "concat.h"

using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::endl;

int main() {
    string str,str2;
    cout<<"first set of strings: "<<endl;
    getline(cin, str);
    cout<<" second set of strings: "<<endl;
    getline(cin,str2);
    vector <string> ret = split(str);
    vector <string> ret2 = split(str2);
    ret = frame(ret);
    ret2 = frame(ret2);

    vector<string>final = hor_concat(ret,ret2);
    print_ret(final);

    cout<<"-------------------"<<endl;
    final = vertical_cat(ret,ret2);
    print_ret(final);

}



