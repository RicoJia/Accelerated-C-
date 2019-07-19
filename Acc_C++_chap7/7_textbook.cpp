//
// Created by rico on 6/24/19.
// run g++ -std=c++11 Acc_C++_chap7.cpp 7_textbook.cpp ../Acc_C++_chap5/split_print.cpp ../Acc_C++_chap6/funcs.cpp
// repetition in the same line can be shown

#include "7_textbook.h"
#include <iostream>
#include <map>
#include <string>
#include "../Acc_C++_chap5/split_print.h"
#include "../Acc_C++_chap6/funcs.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

void word_counter()
{
    cout<<"Please enter your words"<<endl;
    string s;
    map<string,int>look_up;
    while(cin>>s){
        ++look_up[s];
    }
    cout<<"Here are the results"<<endl;
    for(auto i = look_up.begin();i!=look_up.end();++i)
        cout<<i->first<<" appears: "<<i->second<<" times"<<endl;
}

void url_word_xref()
{
    vector<string> input;
    read_in(input);                         // read in your input. Can be as messy as SDF!@#
    map<string,vector<int> > url_map,word_map;
    add_url_words_2_map(url_map,word_map,input);
    cout<<"--------------------------------------"<<endl<<"url results: "<<endl;
    print_map(url_map);
    cout<<"--------------------------------------"<<endl<<"word results"<<endl;
    print_map(word_map);
}

void read_in(vector<string>& input)
{
    string line;
    while(getline(cin,line))
    {
        input.push_back(line);
    }
}

void add_url_words_2_map(map<string,vector<int> >& url_map,map<string,vector<int> >& word_map,const vector<string>& input)
{
    for(auto i = 0;i<input.size();++i )
    {
        vector<string> word_breakdown = split(input[i]);        // break down each word.
        for (auto j = word_breakdown.begin();j!=word_breakdown.end();++j)
        {
            string::const_iterator beg = (*j).begin(), end = (*j).end();
            while (beg!=end)
            {
                string::const_iterator temp = beg;
                beg = url_beg(beg,end);     //find where a valid url begins
                if(beg!=end)
                {           //URL is found
                    string::const_iterator after = url_end(beg,end);
                   url_map[string(beg,after)].push_back(i);
                    beg = after;
                }
                else if (temp!=beg) word_map[string(temp,beg)].push_back(i);        // push back non-empty string as a word
            }
        }

    }
}

void print_map(const map<string,vector<int> >& my_map)
{
    for (auto i = my_map.begin();i!=my_map.end();++i)
    {
        cout<<i->first<<" has appeared in line: ";
        for(auto vec_itr = (i->second).begin();vec_itr!=(i->second).end();++vec_itr)
        {
           cout<<"#"<<*vec_itr<<" "<<endl;
        }
    }
}
