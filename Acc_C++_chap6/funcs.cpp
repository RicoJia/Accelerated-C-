//
// Created by rico on 6/11/19.
//

#include "funcs.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <list>

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::search;
using std::find_if;
using std::find;
using std::list;

void palindrome_main()
{
    // Assume the input is one single line input
    cout<<"Palindrome analyzer: enter your string! "<<endl;
    string input;
    getline(cin,input);
    cout<< ((equal(input.begin(),input.end(),input.rbegin())) ?"yes the input is palindrome":"no it is not palindrome")<<endl;
}

void url_finder()   //input: string; output: vector<string>
{
    cout<<"url analyzer: enter your string! "<<endl;
    string input;
    getline(cin,input);
    vector<string>output;
    typedef string::const_iterator iter;
    iter beg = input.begin();
    iter end = input.end();

    while (beg!=end)
    {
        beg = url_beg(beg,end);
        if(beg!=end) {           //in case there is no valid address
            iter after = url_end(beg,end);
            output.push_back(string(beg,after));
            //cout<<string(beg,after);
            beg = after;
        }
    }
    print_str_vec(output);
}

std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e)       //returns e if nothing is found
{
    typedef string::const_iterator iter;
    static const string mark = "://";
    string::size_type size = mark.size();
    //iter i = find(b,e,mark);
    iter i = search(++b,e,mark.begin(),mark.end()); //i cannot be the first element.
    while(i!=b&&i!=e){    // return the iterator of the first valid item
        if((i+size)==e) return e;
        if(not_url_ch(i[size])||!isalpha(*(i-1)))
            i = search(i+size,e,mark.begin(),mark.end());
        else
            //found a valid url's existence, then let's find the beginning of the address
        {
            while (i >= b && isalpha(i[-1]))
                --i;
            break;  // break out of this loop once we have found the beginning of the address.
        }
    }

    return i;
}
std::string::const_iterator url_end(std::string::const_iterator in_beg, std::string::const_iterator in_end)   // we know input already has alphabetic before "://"
{
    return find_if(in_beg,in_end,not_url_ch);
}
bool not_alpha_num(char c)
{
    return !isalnum(c);
}
bool not_url_ch(char c)
{
    static const string sym= "~;/?:@=&$-_.+!*'(),";
   // return not_alpha_num(c)&&(find(sym.begin(),sym.end(),c)==sym.end());
    return !isalnum(c)&&(find(sym.begin(),sym.end(),c)==sym.end());

}
void print_str_vec(const std::vector<std::string>& vec)
{
    for(auto i = vec.begin();i!=vec.end();++i)
    {
        cout<<*i<<endl;
    }
}

void hw_3()
{
    vector<double> v= {5,4,3,2,1};
    list<double> l;
    copy(v.begin(),v.end(),front_inserter(l));
    cout<<*(l.begin())<<endl;
}