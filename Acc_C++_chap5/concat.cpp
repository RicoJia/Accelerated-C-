//
// Created by rico on 5/31/19.
//
#include "concat.h"
#include "frame_width.h"
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::endl;
using std::cout;

vector <string> hor_concat(const vector<string>& left, const vector <string>& right)
{
    /*vector<string>::size_type length = 0;
    //using reference in the same function??
    vector<string> vec_to_pad;
    bool flag;
    if(left.size()>right.size())
    {
        length = left.size();
        vec_to_pad = right;
        flag = 0;
    }
    else
    {
        length = right.size();
        vec_to_pad = left;
        flag = 1;
    }

    string::size_type vec_wid = width(vec_to_pad);

    string bottom = *(vec_to_pad.rbegin());
    vec_to_pad.erase(vec_to_pad.end());
    string temp= "**"+string(vec_wid-4,' ')+"**";
    vec_to_pad.resize(length,temp);
    *(vec_to_pad.rbegin()) = bottom;

    vector<string> concat;
    if (flag ==0)
    {
        for (auto i = 0; i!=length;++i)
        {
            concat.push_back(left[i]+'|'+vec_to_pad[i]);
        }
    }
    else
    {
        for (auto i = 0; i!=length;++i)
        {
            concat.push_back(vec_to_pad[i]+'|'+right[i]);
        }
    }*/
    string::size_type r_width = right[0].size(), l_width = left[0].size();
    vector<string> concat;
    vector<string>::const_iterator l = left.begin(),r = right.begin(),l_end = left.end(), r_end=right.end();
    while(l!=l_end||r!=r_end)
    {
        string s;
        if(l!=l_end)
        {
            s +=*l;
            ++l;
        }
        else
            s+=(' ',l_width);
        if(r!=r_end)
        {
            s+=*r;
            ++r;
        }
        concat.push_back(s);
    }

    return concat;
}

vector <string> vertical_cat(const vector<string>& top, const vector<string>& bottom)
{
    vector <string> vec = top;
    vec.insert(vec.end(),bottom.begin(),bottom.end());
    return vec;
}

