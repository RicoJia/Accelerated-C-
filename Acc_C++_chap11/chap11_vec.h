//
// Created by rico on 7/24/19.
/*
 * Readme: this file is to implement vec class. Features include:
 * 1. vec(): empty vector, including an empty array; vec(int): assign memory for unitialized space in vec;
 *    vec(beg, avail): copy the content of the given vec; vec(int,T): initialize vec with T
 *    vec(vec): copy a vector
 * 2. ~ vec() - destructor, especially the array pointer.
 * 3. copy: copy another vec's content. useful in vec(vec), copy assignement
 * 4. assignment: here it's just assignment, not copy.  ？？？
 * 7.[]: index, access
 * 5. iterator: it's actually array pointer     - include .begin(), .end(), .capacity(), .size()
 * 6. memory management: allocate 2x space when size = capacity
 * 7. push_back()
 * 8. size_type
 */
//

#ifndef ACCELERATED_C_TEXTBOOK_H
#define ACCELERATED_C_TEXTBOOK_H
#include<cstddef>           //for size_t
#include <memory>           // for std::allocator
#include <iostream>
#include <initializer_list>     // for initializer
#include <algorithm>            //max

template<typename T>
class vec
{
public:
    typedef std::size_t size_type;
    typedef T* iterator;
    typedef const T* const_iterator;
//----------------------------------
    vec(){crear();}
    explicit vec(size_type i, const T& val = T()){crear(i,val);}          // everything comes with a default constructor.
  //  vec(iterator beg, iterator avail){crear(beg, avail);}             // you don't need this because you can use below on regular iterator and do the same thing!
    vec(vec::const_iterator beg, vec::const_iterator avail){crear(beg, avail);}     //THIS is Valid Syntactic sugar!
    vec(const vec<T>& v_obj){crear(v_obj.begin(),v_obj.end());}                       //can do vec<int>v = v2;
    vec(const std::initializer_list<T> l){crear(l);}
    ~vec(){uncrear();}
    //----------------------------------
    iterator begin(){return arr_beg;}
    const_iterator begin()const{ return arr_beg;}
    iterator end(){ return  arr_avail;}
    const_iterator end() const{ return arr_avail;}          //const_iterator further makes sure
    //----------------------------------
    vec& operator= (const vec& v){if(&v!=this){uncrear();crear(v.begin(),v.end());}}            //TODO: how to distinguish bw assignement and copy. 2. use const to fit both const vec and vec
    T& operator[] (size_type i){if(i<arr_avail-arr_beg){return *(arr_beg+i);}}
    const T& operator[] (size_type i) const {return *(arr_beg+i);}
    //----------------------------------
    vec<T>& push_back(const T&);
    void clear();
    size_type size()const{return (arr_lim - arr_beg);}

private:
    T* arr_beg;         //shouldn't do T* a, b cuz that's equivalent to T *a, b!
    T* arr_lim;
    T* arr_avail;       // size and capacity can be calculated by arr_lim - arr_beg
    std::allocator<T> alloc;
    void crear();
    void crear(size_type i, const T&);
    void crear(const_iterator, const_iterator);
    void crear(const std::initializer_list<T>&);
    void uncrear();
    void grow();
};
template <typename T>
void vec<T>::crear() {
    arr_avail = 0; arr_beg = 0; arr_lim = 0;            //TODO: there was a typo and it destroyed the whole thing!
}

template <typename T>
void vec<T>::crear(std::size_t i, const T &val)  {
   arr_beg = alloc.allocate(i);
   arr_avail = arr_lim = arr_beg + i;
   std::uninitialized_fill(arr_beg,arr_avail,val);
}

template <typename T>
void vec<T>::crear(vec<T>::const_iterator beg, vec<T>::const_iterator avail)
{
    arr_beg = alloc.allocate(avail-beg);
    arr_avail = arr_lim = arr_beg +  (avail-beg);
    std::uninitialized_copy(beg,avail,arr_beg);
}


template <typename T>
void vec<T>::crear(const std::initializer_list<T>& l)       //0,0,3?
{
    arr_beg = alloc.allocate(l.size());
    arr_avail = arr_lim = arr_beg + l.size();
    for (auto i = l.begin(),j = arr_beg;i!=l.end();++i,++j) {
        std::uninitialized_fill(j,j+1,*i);
    }
}


template<typename T>
void vec<T>::uncrear() {
    if(arr_beg)
    {
        while (arr_avail!=arr_beg)
            alloc.destroy(--arr_avail);         //TODO: this is important, not arr_avail--!!
        alloc.deallocate(arr_beg,arr_lim -arr_beg);
    }
    arr_beg = arr_lim = arr_avail = 0;

}

template <typename T>
void print_vec(const vec<T>& v)
{
    std::cout<<"-----------------------------------"<<std::endl;
    for (auto i = v.begin();i!=v.end();++i)
    {
        std::cout<<*i<<" "<<std::endl;
    }
}

template<typename T>
vec<T>& vec<T>::push_back(const T& val)
{
    grow();
    //*(arr_avail++)  = val;         //TODO: see if this works?
    alloc.construct(arr_avail++,val);
    //arr_avail;
    return *this;
}

template <typename T>
void vec<T>::grow()
{
    if (arr_avail - arr_lim ==0 || arr_beg == 0)
    {
        size_type sz = arr_lim - arr_beg;
        size_type target_sz = std::max(sz*2,size_type(1));
        T* temp_beg = alloc.allocate(target_sz);
        T* temp_lim = temp_beg + target_sz;
        T* temp_avail = std::uninitialized_copy(arr_beg,arr_avail,temp_beg);
/*        stdext::checked_array_iterator<T*> checked_data(new_data, new_size);
        iterator temp_avail = (std::uninitialized_copy(data, avail, checked_data))._Unchecked();*/
        uncrear();
        arr_beg = temp_beg; arr_avail = temp_avail; arr_lim = temp_lim;
    }
}


template <typename T>
void vec<T>::clear() {
    while(arr_avail!=arr_beg)
        alloc.destroy(--arr_avail);
}

int test_vec();
#endif //ACCELERATED_C_TEXTBOOK_H
