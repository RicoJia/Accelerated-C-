//
// Created by rico on 6/21/19.
// this file implements a vec class that 1. vec(), vec(2),vec(2,'b') 2.vec1 = vec 2  3. vec[n] r/w 4. return begin, end 5. push_back
//

#ifndef C_EXAMPLES_CHAP10_FUNCS_H
#define C_EXAMPLES_CHAP10_FUNCS_H

#include <cstddef>
#include <memory>
#include <algorithm>
#include <iostream>

template <typename T>class vec
{
public:
    typedef size_t size_type;
    typedef  T* iterator;
    typedef const T* const_iterator;
    typedef T value_type;
    // constructors
    vec(){create();};
    explicit vec(size_type n, const T& val = T()){create(n,val);};
    vec(const T& v){create(v.begin_func(),v.avail_func());}
    ~vec(){uncreate();std::cout<<"calling destructor"<<std::endl;} //

    //define [] and =
    size_type size() const {return end-begin;}
    T& operator[] (size_type n){return n[begin];}
    const T& operator[](size_type n)const {return n[begin];}        // lol

    vec& operator=(const vec&);
    //iterator functions
    iterator begin_func(){return begin;}
    iterator end_func(){return end;}
    iterator avail_func(){return avail;}
    const_iterator begin_func() const {return begin;}
    const_iterator end_func() const {return end;}
    const_iterator avail_func()const {return avail;}
    void push_back(const T&);

private:
    // data members
    iterator begin;
    iterator end;
    iterator avail;

    std::allocator<T> alloc;
    //utility functions
    void grow();
    void append(const T&);

    void uncreate();
    void create();
    void create(size_type n, const T&);
    void create(const_iterator, const_iterator);
};


template <typename out, typename in>  out uninitialized_copy(in i_beg, in i_end, out o_beg)     //returns the end of output iterator.
{
    while(i_beg!=i_end)
    {*o_beg++ = *i_beg++;
             }
        return o_beg;
}

template <typename out, typename i> void uninitialized_fill(out o_beg, out o_end, const i& val)
{
    while(o_beg!=o_end)
        *o_beg++ = val;
}

//-----------------------------------------------------------------------------------------
template <typename T> vec<T>& vec<T>::operator=(const vec& rhs){
    if(&rhs!=this)
    {
        uncreate();
        create(rhs.begin_func(),rhs.avail_func());

    }
    return *this;
};
    //-----------------------------------------------------------------------------------------
template <typename T> void vec<T>::push_back(const T& val)
{
    if(avail==end)
        grow();
    append(val);
}

template<typename T> void vec<T>::grow()    // twice as much memory, copy, destroy, and finally deallocate
{
    size_type new_size = std::max(2*size(),size_type(1));    //what if size = 0?
    iterator new_begin = alloc.allocate(new_size);
    iterator new_avail = ::uninitialized_copy<iterator,iterator>(begin,avail,new_begin);
    uncreate();
    begin = new_begin; avail = new_avail; end = begin+new_size;
}

template<typename T> void vec<T>:: append(const T& val)
{
//
//    *avail = val;
//    ++avail;
    alloc.construct(avail++, val);
}
//-----------------------------------------------------------------------------------------
template<typename T> void vec<T>::uncreate()     // destruct the array, deallocate the memory, free pointers.
{
    while (avail!=begin)
        alloc.destroy(avail--);
    alloc.deallocate(begin,end-begin);
    begin = avail = begin = 0;
}

template<typename T> void vec<T>::create() {
    begin = avail = end = 0;
}

template <typename T> void vec<T>::create(size_type n, const T& val)
{
    if(n!=0){
        begin = alloc.allocate(2*n);
        end = begin+2*n;
        avail = begin+n;
        ::uninitialized_fill<iterator,T>(begin,avail,val);

    }
    else
    {
        begin = avail = end = 0;
    }

}
template<typename T> void vec<T>::create(const_iterator i_beg, const_iterator i_avail)
{
    if(i_beg!=i_avail)
    {
        size_type new_size = 2*(i_avail-i_beg);
        begin = alloc.allocate(new_size);
        avail = ::uninitialized_copy<iterator,const_iterator>(i_beg,i_avail,begin);
        end= begin+new_size;
    }
    else
    {begin=avail=end=0;}

}
#endif //C_EXAMPLES_CHAP10_FUNCS_H
