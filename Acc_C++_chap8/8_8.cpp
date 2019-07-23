//
// Created by rico on 7/19/19.
//

#include "8_8.h"
#include <iostream>
#include <iterator>
using namespace std;

template <typename T, typename V>
bool binary_search_algo_8_8(T beg, T end, V val)
{
    if(*beg==val) return true;
    if(beg+1==end) return false;
    T temp1 = beg+(end-beg)/2;
  T temp2 = (beg+end)/2;
    if(*temp1<=val) binary_search_algo_8_8(temp1,end,val);
    else binary_search_algo_8_8(beg,temp1,val);
}

void test_8_8()
{
    int p1[] = {1,2,3};
   /* for (int i = 0; i!=8; ++i)          //test passed
        cout<<binary_search_algo_8_8(begin(p1),end(p1),i)<<endl;*/
   cout<<binary_search_algo_8_8(begin(p1),end(p1),1.0);
}