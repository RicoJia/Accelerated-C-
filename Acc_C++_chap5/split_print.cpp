//
// Created by rico on 5/31/19.
//
#include "split_print.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::find_if;

/*vector <string> split(const string& str)
{
    vector<string> ret;
    string::size_type size = str.size();
    auto i = str.begin(); auto j = i;       //use j on str here?
    while (i!=str.end()){
        while(isspace(*i))
            ++i;

        j=i;
        while(!isspace(*j)&&j!=str.end())
            j++;


        if(i!=j){       //what if it's a whole white space? i is always j.
            string temp(i,j);
            ret.push_back(temp);
            i=j;
        }

    }

    return ret;
}*/
vector <string> split(const string& str)    //FINDS WORDS and spaces
{
    vector<string> ret;
    string::size_type size = str.size();
    auto i = str.begin(); auto j = i;       //use j on str here?
    while (i!=str.end()){
        i = find_if(i,str.end(),not_space);
        j=find_if(i,str.end(),is_space);

        if(i!=j){       //what if it's a whole white space? i is always j.
            string temp(i,j);
//            cout<<temp<<endl;
            ret.push_back(temp);
            i=j;
        }
    }

    return ret;
}

void print_ret(const vector<string>& ret)
{
    for(auto i=ret.begin();i!=ret.end();++i)
    {
        cout<<*i<<endl;
    }
}

bool is_space(char c)
{
    return isspace(c);
}
bool not_space(char c)
{
    return !isspace(c);
}