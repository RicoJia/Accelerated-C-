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
#include <algorithm>
#include <vector>
#include <list>

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

template <typename T1, typename T2> T2 remove_copy_if_algo(T1 beg, T1 end, T2 beg_2,bool(*pred)(T1))
{               //TODO: Try functors here
    while (beg!=end)
    {
       if(!pred(beg))
           
           *beg_2++ = *beg;  //why beg has to move? well, a random access iterator doesn't have to move at all!
       ++beg;
    }
    return beg_2;
}

template <typename T> bool comp_remove_cope_if(T itr)       // IMPORTANT: when you call this function, you need to supply the type of T with the function pointer, as a function pointer cannot point to a template, it needs to point to an "instantiation of the template", whose type should be clear!!!
{
    return (*itr<=3)?true:false;
}
void test_remove_copy_if();

template <typename T,typename V>
T remove_algo(T beg, T end,V val)
{
    T temp = beg;
    while (beg!=end)
    {
        if(*beg != val)
            *temp++ = *beg++;
        else
            ++beg;
    }
    return temp;
}
void test_remove();

template<typename T, typename V,typename Pred>
void transform_algo(T beg, T end, V beg_2, Pred f)
{
    while (beg!=end)
    {
        *beg_2++ = f(beg++);          //Yes it works!
    }
}
bool increment(double a);
void test_transform();

template <typename T, typename V>
V accumulate_algo(T beg, T end, V init_val)
{
    while (beg!=end)
        init_val+=*beg++;
    return init_val;
}
void test_accumulate();

template <typename T1, typename T2>
T1 search_algo (T1 beg1, T1 end1, T2 beg2, T2 end2)         // you can use std::end(array) to access the end of the array.
{
    
    if (beg2==end2) return end1;
    T1 temp1;
    T2 temp2;
    for (;beg1!=end1;++beg1)                // ++beg1 is executed at the end of each iteration
    {
        temp1 = beg1;
        temp2 = beg2;
        while (*temp1==*temp2)             /* how to evaluate *temp2 when temp2 is end2? A: You don't evaluate it. btw, the cpp reference of this algo is wrong as while will evaluate the end iterators. http://www.cplusplus.com/reference/algorithm/search/*/
        {
            if (temp2+1==end2) return beg1;
            if (temp1 == end1) return end1;
            ++temp1; ++temp2;
        }
    }
    return end1;
}
void test_search();

template <typename T, typename pred>
T find_if_algo(T beg, T end, pred f)
{
    while (beg!=end)
    {
        if (f(*beg)) return beg;  //Important detail: f(beg) or f(*beg)? A: f(*beg++)
        ++beg;      //Also important: never do (beg++) if you want to return beg.
    }
    
    return end;
}

class find_ur_num
{
public:
    find_ur_num(int n):num(n){}
    bool operator()(int c){return c==num;}      //overloading ()
private:
    int num;
};

void test_find_if();

//TODO: std::move in std::remove?
template<typename T, typename pred>     //THIS IS FROM TEXTBOOK. AMAZING!!!
T partition_algo(T beg, T end, pred f)
{
    while (beg!=end)
    {
        while(f(*beg))
        {
            ++beg;
            if(beg==end) return end;
        }
        do{
            --end;
            if(beg == end) return beg;
        }
        while(!(f(*end)));
        std::swap(*beg,*end);
        ++beg;
    }
    return beg;
}

class less_than_ur_num
{
public:
    less_than_ur_num(int n):num(n){}
    bool operator()(int c){return c<num;}      //overloading ()
private:
    int num;
};
void test_partition();

//8-2

double find_median(std::vector<double> vec);
template<typename List_stu, typename F>
double median_analysis(List_stu&stus, F func)
{
    std::vector<double> grades;
    transform(stus.begin(),stus.end(),back_inserter(grades),func);
    return find_median(grades);
}

// 8-3      - Duh you need to sort the vector, which will change the value of the vec.
//8-4       - you're just going to swap the two pointers while the vector stays the same!!

#endif /* __funcs_hpp */
