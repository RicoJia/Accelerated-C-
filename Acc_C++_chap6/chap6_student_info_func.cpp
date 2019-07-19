//
// Created by rico on 6/11/19.
//

#include "chap6_student_info_func.h"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::back_inserter;
using std::transform;
using std::domain_error;
using std::list;
using std::vector;
using std::copy_if;
using std::partition;
using std::stable_partition;

istream& student::read_grades(std::istream& in)
{
    cout<<"Hello, please enter the student's name here"<<endl;
    getline(in,name);
    if(!in) return in;
    cout<<"Hi "<<name<<", please enter your midterm and final grades here"<<endl;
    in>>mt>>fn;
    if(!in) return in;

    //read homework
    cout<<"Please enter all your homework values here, closed by end of file"<<endl;
    hw.clear(); // clear the vector if it has anything.
    double input = 0;
    while(in>>input)
    {
        hw.push_back(input);
    }
    in.clear(); // clear any state that indicates failure in reading. finishing cin will change the status of cin to error?? End-of-file is considered as an error and if there are errors incurred in the input process, we need to clear so future cin will work properly.

    return in;   //might be empty,end-of-file, return the status of reading cin, and write cin into homework.
}

double student::true_grade()    //This is a wrapper for grade
{
    if(hw.empty())
        throw domain_error("the student has no homework");
    return 0.2*mt+0.4*fn+0.4*::find_median(hw);
}

double student::grade()
{
    try {
        return true_grade();
    }
    catch (domain_error)
    {
        hw={0};
        return true_grade();
    }
}

void student::pad_0(vector<double>::size_type hw_num)
{
    vector<double>::size_type stu_num = hw_size_check();
    vector<double> padding (hw_num-stu_num,0);
    hw.insert(hw.end(),padding.begin(),padding.end());
}

double grade_aux(student& stu)
{
    return stu.grade();
}

bool name_cmp(student& a, student& b)
{
    return (a.get_name()<b.get_name())?true:false;
}

bool did_all_hw(std::vector<double>::size_type stu,std::vector<double>::size_type teacher)
{
    return (stu<teacher)?false:true;
}

void write_analysis(ostream& out, string name_analysis, double analysis(list<student>&),list<student>& did, list<student>& didnt)
{
    out<<"Here is the result of students who did the homework: "<<name_analysis<<"- "<<analysis(did)<<"\t and this is for those who didn't finish everything: "<<name_analysis<<
    "- "<<analysis(didnt)<<endl;
}

double median_analysis(list<student>&stus)
{
    vector<double> grades;
    transform(stus.begin(),stus.end(),back_inserter(grades),grade_aux);
    vector<double>::iterator iter = partition(grades.begin(),grades.end(),pgrade);
    vector<double> pgrades (grades.begin(),iter);
    grades.erase(grades.begin(),iter);
    cout<<pgrades.size()<<" passed, "<<grades.size()<<"failed. "<<endl;
    try {
        return find_median(grades);
    }
    catch (domain_error)
    {
        return 0;
    }
}

double find_median(vector<double> vec)
{
    typedef vector<double>::size_type vectorsz;
    vectorsz size = vec.size();
    if(size == 0)
        throw domain_error("Find Median: the vector is empty, no median can be found!");
    sort(vec.begin(),vec.end());
    return (size%2==0)?(vec[size/2]+vec[size/2-1])/2:vec[size/2];     //-1/2 =0, 3/2 = 1;
}

bool pgrade(double grade)
{
    return (grade<passing_grade)?false:true;
}
