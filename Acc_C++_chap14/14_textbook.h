//
// Created by rico on 6/30/19.
//

#ifndef C_EXAMPLES_14_TEXTBOOK_H
#define C_EXAMPLES_14_TEXTBOOK_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class core
{
    template<typename T> friend class handle;     //TODO
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

//-------------------------
template <typename T> class handle
{
public:
    handle():p(0){}
    handle(const handle& s):p(0){if(s.p)p = s.p->clone();}      // copy constructor, so a handle contains a pointer pointing to an obj
    ~handle(){delete p;}
    handle& operator= (const handle& s)
            {if(&s!=this)       //I think we can compare p as well? but this is more generic for sure.
                {delete p;      //Don't forget to delete the pointer.
                p = s.p?s.p->clone():0;}
            return *this;}

    handle(T* t):p(t){}         // for objects created by new

    operator bool()const{return p;}          //type conversion
    T& operator *()const {if (p) return *p; throw std::runtime_error("Object does not exist!");}
    T* operator ->()const {if(p)return p; throw std::runtime_error("Object does not exist!");}      // -> returns a pointer (can be private?) and the compiler will automatically append another -> (required by c++). so you only need c->something

private:
    T* p;
};

class student_handle
{
public:
    student_handle():cp(0){}
    student_handle(std::istream& in):cp(0){read(in);}       //no need for destructor.

    std::istream& read(std::istream& in);
    std::string name()const{if(cp) return cp->name();
        else throw std::runtime_error("The object is empty!");};
    double grade()const;

    static bool compare_Core_handles(const student_handle& a, const student_handle& b)      // you've to make it its own version
    {
        return a.name()<b.name();
    }
private:
    handle<core> cp;
};

std::istream& read_stu_status(std::istream&, char&);
bool compare_Core_handles(const handle<core>& a, const handle<core>& b);
bool compare_Core_ptrs(core*, core*);
bool compare (core&,core&);
void student_info_13();
#endif //C_EXAMPLES_14_TEXTBOOK_H
