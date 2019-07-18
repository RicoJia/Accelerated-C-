//
// Created by rico on 6/30/19.
//

#ifndef C_EXAMPLES_13_TEXTBOOK_H
#define C_EXAMPLES_13_TEXTBOOK_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class core
{
    friend class student_handle;
public:
    double lol;
    core(double m = 50):mt(m){};
    core(std::istream& in){read(in);};
    std::string name()const;
    virtual double grade()const;
    virtual std::istream& read(std::istream&);
    virtual ~core(){}           //as long as you have polymorphism, you want this!

private:
    std::istream& read_common(std::istream&);
    std::string n;
    double mt, fn;
    std::vector<double>hw;

protected:
    virtual core* clone(){return new core(*this);};
};


class grad: public core          // can be private core??
{
public:
    grad(double t = 90, int m =80):core(m),thesis(t){};
    grad(std::istream& in){read(in);}
    double grade() const;
    std::istream& read(std::istream&);
private:
    double thesis;
protected:
    grad* clone(){return new grad(*this);}
};


class student_handle
{
public:
    student_handle():cp(0){}
    student_handle(std::istream& in):cp(0){read(in);}
    student_handle(const student_handle& s):cp(0){if(s.cp)cp =s.cp->clone();}
    student_handle& operator= (const student_handle& s);
    ~student_handle(){delete cp;}       //ofc, if you pointer, you need destructor/dealloc.

    std::istream& read(std::istream& in);
    std::string name()const;
    double grade()const;

    static bool compare (const student_handle& c1,const student_handle&c2){
        return c1.name()<c2.name();}
private:
    core* cp;
};


std::istream& read_stu_status(std::istream&, char&);
bool compare_Core_ptrs(core*, core*);
bool compare (core&,core&);
void student_info_13();
#endif //C_EXAMPLES_13_TEXTBOOK_H
