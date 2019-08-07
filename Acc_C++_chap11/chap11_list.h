//
// Created by rico on 7/27/19.
//

#ifndef ACCELERATED_C_CHAP11_LIST_H
#define ACCELERATED_C_CHAP11_LIST_H

#include <memory>        //std::allocator, unitialized_fill
#include <cstddef>      // size_type
#include <initializer_list>
#include <iostream>
#include <type_traits>          //remove_cv
#include <iterator>
#include <cassert>          //assert

template <typename T>
class node {
    template <typename T1> friend class ls;
    //template <typename T2,bool is_const> friend class node_itr;
    template <typename T2,class unqualified_T> friend class node_itr;
public:
    node():prev(0),after(0){}
    explicit node(const T& d, node* p = 0, node* a = 0){val = d; prev = p; after = a;}
private:
    node* prev;
    node* after;
    T val;
};

/*template <typename T, class unqualified_T = std::remove_cv_t<T> >           //we need to make this a separate class because of b++ and it cannot be in class ls for the underlying ls object
class node_itr              //= , != can be synthesized.
{
public:
    node_itr(node<unqualified_T>* d = 0):data(d){}        //not node_itr& cuz it will be out of scope. but return a new node_itr?? If not, you have to modify data, which means you can never have a const iterator
    ~node_itr(){delete data;}
    node_itr& operator++() {
        if(data!=0){
            data = data->after;     //no need for const as const pointer can change itself, not the object it points to.
            std::cerr<<"in ++, the current value is"<<data->val<<std::endl;
        }
        return *this;
    }
    node_itr operator++(int){
        node_itr temp(this->data);
        if(data!=0)
            data = data->after;
        return temp;
    }
    node_itr& operator--(){
        if(data!=0)
            data = data->prev;
        return *this;
    }
    node_itr operator--(int){
        node_itr temp(this->data);
        if(data!=0)
            data = data->prev;
        return temp;
    }
    T& operator*() const {
        if(data->val)         std::cerr<<"* begins"<<std::endl;
        std::cerr<<""<<std::endl;
        return data->val;
    }
    node<unqualified_T>* operator->()const{
        return data;
    }
    operator node_itr<const T>() const
    {
        return node_itr<const T>(data);
    }

    bool operator==(const node_itr n_itr)const{return (this->data == n_itr.data);}
    bool operator!=(const node_itr n_itr)const {return !(*this==n_itr);}

private:
    node<unqualified_T>* data;
};*/

template<class T, class unqualified_T = std::remove_cv_t<T> >            // specify node_itr<const T> for const_iterator
class node_itr:public std::iterator<
        std::bidirectional_iterator_tag,
        node<T> >
{
public:
    node_itr(node<unqualified_T>* d = 0):data(d){}        //not node_itr& cuz it will be out of scope. but return a new node_itr?? If not, you have to modify data, which means you can never have a const iterator
    ~node_itr(){}
    node_itr& operator++() {
        assert(data!=0);
        data = data->after;     //no need for const as const pointer can change itself, not the object it points to.
        return *this;
    }
    node_itr operator++(int){
        assert(data!=0);
        data = data->after;
        return temp;
    }
    node_itr& operator--(){
        assert(data!=0);
        data = data->prev;
        return *this;
    }
    node_itr operator--(int){
        assert(data!=0);
        data = data->prev;
        return temp;
    }
    T& operator*() const {
        assert(data!=0);
        return data->val;
    }
    node<unqualified_T>* operator->()const{
        assert(data!=0);
        return data;
    }
    operator node_itr<const T>() const
    {
        return node_itr<const T>(data);
    }

    bool operator==(const node_itr n_itr)const{return (this->data == n_itr.data);}
    bool operator!=(const node_itr n_itr)const {return !(*this==n_itr);}           //TODO: why not workng?

private:
    node<unqualified_T>* data;
};

template <typename T>
class ls{
public:
    //typedef node_itr<T,true> iterator;
    //typedef node_itr<T,false> const_iterator;
    typedef node_itr<T> iterator;
    typedef node_itr<const T> const_iterator;
    typedef std::size_t size_type;

    ls():_size(0){_beg=_tail=0;}
    ls(std::initializer_list<T> k):_size(0){ls_crear(k);}
    ls(const ls& s):_size(0){ls_crear(s.begin(),s.end());}
    ls(const_iterator b,const_iterator e):_size(0){ls_crear(b,e);}
    ls& operator= (const ls& s){uncrear();ls_crear(s.begin(),s.end());}
    ls(size_type n, T val):_size(0){
        for(size_type i = 0; i!=n;++i){append(val);}
    }
    ~ls(){uncrear();}

    iterator begin(){return iterator(_beg);}
    const_iterator begin()const {return const_iterator(_beg);}
    iterator end(){return iterator();}
    const_iterator end() const{ return const_iterator();}

    void push_back(const T& val){append(val);}
    void clear(){uncrear();};
    const_iterator erase(const_iterator itr){
        node<T>* temp =0;
        if(_size != 0)
        {
            node<T>* temp =itr->prev;
            node<T>* temp_self = (itr->prev != 0)?itr->prev->after:_beg;
            if(itr->prev!=0)
                itr->prev->after = itr->after;
            else
                _beg = itr->after;
            if(itr->after!=0)
                itr->after->prev = itr->prev;
            else
                _tail = itr->prev;
            --_size;
            delete temp_self;
        }
        return temp;
    };
private:
    node<T>* _beg;
    node<T>* _tail;
    size_type _size;
    std::allocator<node<T> > alloc;

    void ls_crear(std::initializer_list<T> k);
    void ls_crear(const_iterator,const_iterator);
    void uncrear();     //TODO

    //basic utility funcs
    void append(const T&);
};

template <typename T>
void ls<T>::ls_crear(std::initializer_list<T> k)
{
    if(k.size())
    {
       for(auto i = k.begin();i!=k.end();++i) {            // TODO: I don't think we need to overload !=? Let's see
           append(*i);
        }
    }
}

template <typename T>
void ls<T>::ls_crear(const_iterator b, const_iterator e)           //just for creating the list from scratch
{
    while(b!=e)
    {
        append(*b);
        ++b;
    }
}

template <typename T>
void ls<T>::append(const T& v)
{
    node<T>* _temp = new node<T>(v);
    if(_size == 0 ){
        _beg = _temp;            //TODO: Assume = is good for iterators.
        _tail = _temp;           // prev, after are all null.
    }
    else
    {
        _temp->prev = _tail;
        _tail->after = _temp;
        _tail = _temp;
    }
    ++_size;
}

template <typename T>
void ls<T>::uncrear() {
    while(_size!=0)
    {
        node<T>* temp = _tail;
        _tail = _tail->prev;
        delete temp;
        --_size;
    }
    _beg = 0;
    _tail = 0;
}




int test_list();
#endif //ACCELERATED_C_CHAP11_LIST_H
