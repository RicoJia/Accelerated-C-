//
// Created by rico on 5/27/19.
//
#include "median.h"
#include <vector>
#include <stdexcept>
#include <algorithm>  //contains sort!

using std::domain_error;        //这个也tricky
using std::vector;
using std::sort;
/*double median(vector<double> vec)
{
    typedef vector<double>::size_type vectorsz;
    vectorsz size = vec.size();
    if(size == 0)
        throw domain_error("the vector is empty, no median can be found!");
    sort(vec.begin(),vec.end());
    return (size%2==0)?(vec[size/2]+vec[size/2-1]):vec[size/2];     //-1/2 =0, 3/2 = 1;
}*/

