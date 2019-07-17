//
// Created by rico on 6/5/19.
//This file includes: 1. word counter using map
// 2. a cross-reference table that links word with in which line of input it was at. vector<int>, and the split func from chap 5.
//3. write a random sentence generator, that reads grammar from a file, then select random words according to the grammar rule.space in bw words.


#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

void word_counter();

int main()
{
    word_counter();
    return 0;
}

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


