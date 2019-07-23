//
// Created by rico on 7/19/19.
//

#include "8_6.h"
#include <iostream>
using std::cout;
using std::endl;

#include <map>
using std::map;

#include <utility>
using std::pair;

#include <string>
using std::string;

#include <list>
using std::list;

#include <algorithm>
using std::copy;

#include <iterator>
using std::back_inserter;

void test_8_6()
{
    map<int,string> m = {{1,"hola"},{2,"amigo"}};
    list<pair<int,string> > l;
    copy(m.begin(),m.end(),back_inserter(l));
    for(auto i = l.begin();i!=l.end();++i)
        cout<<i->first<<" "<<i->second<<endl;               //注意,这是正确print Map的方式。

}