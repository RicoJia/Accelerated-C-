//
// Created by rico on 6/26/19.
//

#ifndef C_EXAMPLES_12_TEXTBOOK_H
#define C_EXAMPLES_12_TEXTBOOK_H

#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>

using std::copy;
using std::vector;
using std::istream;
using std::ostream;

class Str
{
    friend istream& operator>> (istream& in,Str& s);
    friend ostream& operator<< (ostream& out,Str& s);
public:
    Str(){}
    //const Str(const Str&b){data = b}
    Str(int n, char c):data(n,c){}                                    //1. 能用initializer List的尽量不要用{}; 2. 你Initializer list 原来是在这里call 每个变量的initializer!!!fuck
    Str(const char* arr){copy(arr,arr+strlen(arr),back_inserter(data));}        //1, 还能用copy 哪。 2. copy 需要back_inserter loll 3. type conversion!
    template<typename T> Str(T beg, T avail){copy(beg,avail,back_inserter(data));};
    char& operator[](size_t n){return data[n];}
    const char& operator[] (size_t n)const{return data[n];}

    Str& operator+=(const Str&b){copy(b.data.begin(),b.data.end(),back_inserter(data)); return *this;}

private:
    vector<char> data;      //TODO: use vec in chap 10
};

istream& operator>> (istream&,Str&);
ostream& operator<< (ostream&,Str&);
Str operator+ (const Str&, const Str&);
#endif //C_EXAMPLES_12_TEXTBOOK_H
