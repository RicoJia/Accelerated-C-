//
// Created by rico on 6/30/19.
//

#include "13_textbook.h"
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
student_handle& student_handle::operator= (const student_handle& s)
{
    if(this!=&s)            //self-assignment
    {
        delete cp;          //clear pointer
        if(s.cp)
            cp = s.cp->clone();
        else
            cp = 0;
    }
    return *this;
}

std::istream& student_handle::read(std::istream& in)
{
    delete cp;      //???why do we meed to delete if this function is only used by the constructor???
    char u;
    if(read_stu_status(in,u)&&u=='u')
        cp = new core(in);
    else if(u=='g')
        cp = new grad(in);
    return in;
}

std::string student_handle::name()const {
    if(cp) return cp->name();
    else throw std::runtime_error("The object is empty!");
}

double student_handle::grade()const {
    if(cp) return cp->grade();
    else throw std::runtime_error("The object is empty!");}


//-------------------------------------------------------------------------------------------------------
bool compare_Core_ptrs(core* c1, core* c2)      //auxilary function for compare, so that it can be passed as template argument.
{
    return compare(*c1, *c2);
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
//-------------------------------------------------------------------------------------------------------
void student_info_13()
{
    vector<core*> stu_handle_list;
    core* record;
    char u;
    string::size_type maxlen = 0;

    while(read_stu_status(cin,u))
    {
        if (u=='u')
            record = new core;
        else if (u=='g')
            record = new grad;
        record->read(cin);
        max(maxlen,record->name().size());
        stu_handle_list.push_back(record);
    }

    sort(stu_handle_list.begin(),stu_handle_list.end(),compare_Core_ptrs);

    for (vector<core*>::const_iterator i = stu_handle_list.begin(); i!= stu_handle_list.end();++i)
    {
        try{
            double final_grade = (*i)->grade();
            streamsize prec = cout.precision();
            cout<<(*i)->name()<<" 's final grade is "<<setprecision(3)<<final_grade<<setprecision(prec)<<endl;
        }
        catch (domain_error e){cout<<e.what();}
        delete(*i);
    }
}

//-----------------
void student_info_13_2()
{
    vector<student_handle> stu_handle_list;
    student_handle stu_handle;
    string::size_type maxlen = 0;

    while(stu_handle.read(cin))
    {
        maxlen = max(maxlen,stu_handle.name().size());
        stu_handle_list.push_back(stu_handle);
    }

    sort(stu_handle_list.begin(),stu_handle_list.end(),student_handle::compare);

    for (vector<student_handle>::const_iterator i = stu_handle_list.begin(); i!= stu_handle_list.end();++i)
    {
        try{
            double final_grade = i->grade();
            streamsize prec = cout.precision();
            cout<<i->name()<<" 's final grade is "<<setprecision(3)<<final_grade<<setprecision(prec)<<endl;
        }
        catch (std::runtime_error e){cout<<e.what();}
    }
}