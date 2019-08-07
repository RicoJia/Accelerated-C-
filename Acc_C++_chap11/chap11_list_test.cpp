//
// Created by rico on 7/27/19.
//

#include "chap11_list.h"
#include <iostream>

using std::endl;
using std::cin;
using std::cout;

int test_list()
{
    //iterator test
/*    node_itr<int> a = 0;
    node<int> n_1;
    node<int>n_2(3);            //We do not support node = val!
    node_itr<int> b(&n_2);      //this is node*, not a node!
    cout<<(b*)<<endl;*/


    // constructor tests

   const ls<int> b = {1,2,3};
   ls<int> a(b.begin(),b.end());
   ls<int> c = b;//implicit conversion: c(b)
   ls<int> d = {5,6,7};
   d = b;
   ls<int> e(1,1000);
    //other utility test: clear, erase, push_back,size()

   e.clear();
//   e.push_back(1212);
   /*e.erase(e.begin());   e.clear();*/

/*    ls<int>::iterator i = e.begin();
    std::cerr<<"done begin"<<std::endl;

    ls<int>::iterator k= e.end();
    std::cerr<<"done end"<<std::endl;*/

/*    std::cerr<<"marker 0"<<std::endl;
    if (!(i!=k))  std::cerr<<"not equal"<<std::endl;*/
    std::cerr<<"marker1"<<std::endl;
    cout<<*(e.begin())<<endl;
/*    for(ls<int>::const_iterator i = e.begin();i!=e.end();++i) //basic utility test: *, ++,--, !=. 注意： *(iterator) is not necessary cuz iterator is T*
    {
        cout<<"e contains "<<*i<<endl;
    }*/


    return 0;
}
