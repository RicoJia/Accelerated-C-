//
// Created by rico on 6/3/19.
//
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <iomanip>
#include <numeric>
#include <stdexcept>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::setw;
using std::stringstream;
using std::string;

void squares_main();
void print_double_vec(const vector<double>&,const vector<double>&,string::size_type, string::size_type);
void average();

int main()
{
    squares_main();
    return 0;
}

void squares_main()
{
    vector<double> original;
    vector<double> squares;
    string::size_type o_size = 0, s_size = 0;
    double input;
    while(cin>>input)
    {
        original.push_back(input);
        stringstream ss;
        ss<<input;
        o_size = max(o_size,ss.str().size());
        ss.str("");
        double square = input*input;
        squares.push_back(square);
        ss<<square;
        s_size = max(s_size,ss.str().size());
        ss.str("");
    }
    print_double_vec(original,squares,o_size,s_size);
}
void print_double_vec(const vector<double>& left,const vector<double>& right,string::size_type l_d, string::size_type r_d)
{
    vector<double>::size_type l_size = left.size();
    for(vector<double>::size_type i=0;i!=l_size;++i)
    {
        cout<<std::left<<setw(l_d)<<left[i]<<" "<<setw(r_d)<<right[i]<<endl;
    }
}

void average()
{
    using std::domain_error;
    using std::accumulate;
    vector<double> nums;
    double num;
    while(cin>>num)
    {
        nums.push_back(num);
    }
    try {

        if(nums.size()==0) throw domain_error("empty vector!");

        cout<<"average is "<<accumulate(nums.begin(),nums.end(),0.0)/nums.size()<<endl;
    }
    catch(domain_error e){cout<<e.what();}
}
