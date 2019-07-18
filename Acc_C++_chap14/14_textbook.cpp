//
// Created by rico on 6/30/19.
//

#include "14_textbook.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <ios>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::sort;
using std::string;
using std::istream;
using std::domain_error;
using std::streamsize;
using std::setprecision;

string core::name() const {return n;}
double core::grade() const { return mt;}
double grad::grade() const {cout<<thesis; return thesis;}
istream& core::read(istream& in) {return in;}
istream& grad::read(istream& in) {return in;}

//-------------------------------------------------------------------------------------------------------
std::istream& student_handle::read(std::istream& in)
{
    char u;     //cp does not need to be deleted. because cp could be 0 or something, and in handle = operator, the old object has been deleted.
    if(read_stu_status(in,u)&&u=='u')
        cp = new core(in);
    else if(u=='g')
        cp = new grad(in);
    return in;
}

/*std::string student_handle::name()const {
    if(cp) return cp->name();
    else throw std::runtime_error("The object is empty!");
}*/

double student_handle::grade()const {
    if(cp) return cp->grade();
    else throw std::runtime_error("The object is empty!");}


//-------------------------------------------------------------------------------------------------------
bool compare_Core_ptrs(core* c1, core* c2)      //auxilary function for compare, so that it can be passed as template argument.
{
    return compare(*c1, *c2);
}

bool compare_Core_handles(const handle<core>& a, const handle<core>& b)
{
    return a->name()<b->name();
}

bool compare (core& c1,core& c2)        // as long as c1 c2 are grad, polymorphism can be achieved
{
    return c1.grade()<c2.grade();
}

istream& read_stu_status(istream& in, char& c)
{
    do{
        cout<<"What is the student type? u for undergrad, g fro Grad"<<endl;
        in>>c;
        if (c!='u'&&c!='g') cout<<c<<" Invalid Input"<<endl;
    }
    while (c!='u'&&c!='g');

    return in;
}
//-----------------
void student_info_14_1()
{
    vector<handle<core> > handle_list;          // here the type core only determines the type of pointer inside handle, has nothing to do with memory management!???
    handle<core> handle;
    string::size_type maxlen = 0;

    char c;
    while(read_stu_status(cin,c))
    {
        if (c == 'u')
            handle = new core;              //using the handle(T* t):p(t){} constructor and type conversion, demonstrating pointer like behaviour
        else if (c == 'g')
            handle = new grad;
        handle->read(cin);                  // demonstrating pointer like behaviour. More advanced than a read function inside handle!
        maxlen = max(maxlen,handle->name().size());
        handle_list.push_back(handle);
    }

    sort(handle_list.begin(),handle_list.end(),compare_Core_handles);       //TODO

    for (auto i = handle_list.begin(); i!= handle_list.end();++i)
    {
        try{
            double final_grade = (*i)->grade();
            streamsize prec = cout.precision();
            cout<<(*i)->name()<<" 's final grade is "<<setprecision(3)<<final_grade<<setprecision(prec)<<endl;
        }
        catch (std::runtime_error e){cout<<e.what();}
    }
}