//
//  8_funcs.hpp
//  8_funcs
//
//  Created by LOGIN on 2019-07-15.
//  Copyright © 2019 LOGIN. All rights reserved.
//

#ifndef __funcs_hpp
#define __funcs_hpp

#include <stdio.h>

template <typename T1, typename T2> bool equal_algo(T1 beg, T1 end, T2 beg_2)
{
    while (beg!=end)
        if (*beg++!=*beg_2++)       //while,if needs a compound statement, which is {}. Expression is the thing which is to be evaluated
            return false; 
    return true;
}
void test_equal();

template<typename T, typename V> T find_algo(T beg, T end, V val)
{
    while(beg!=end)
        if(*beg++ == val)
            return beg;
    return 0;         // I didn't want to return end because that's still a pointer. Here I'd rather return null
}
void test_find();

template <typename T1, typename T2> T2 copy_algo(T1 beg, T1 end, T2 beg_2)
{
    while(beg!=end)
        *beg_2++ = *beg++;          //Attention: copying stuff to empty vector is not allowed. You need to specify the size first
    return beg_2;
}
void test_copy();
void test_remove_copy_if();

template <typename T1, typename T2> T2 remove_copy_if_algo(T1 beg, T1 end, T2 beg_2,bool(*pred)(T1))
{
    while (beg!=end)
    {
       if(!pred(beg))
           
           *beg_2++ = *beg;  //why beg has to move? well, a random access iterator doesn't have to move at all!
       ++beg;
    }
    return beg_2;
}

template <typename T> bool comp_remove_cope_if(T itr)
{
    return (*itr<=3)?true:false;
}



#endif /* __funcs_hpp */
