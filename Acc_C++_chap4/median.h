//
// Created by rico on 5/27/19.
//

#ifndef C_EXAMPLES_MEDIAN_H
#define C_EXAMPLES_MEDIAN_H
#include <vector>
#include <stdexcept>
#include <algorithm>  //contains sort!

using std::domain_error;        //这个也tricky
using std::vector;
using std::sort;
template <class T> double median(vector<T> vec)
{
    typedef vector<T>::size_type vectorsz;
    vectorsz size = vec.size();
    if (size == 0)
        throw domain_error("Peligroso!");
    sort(vec.begin(),vec.end());
    return (size%2)?(vec[size/2]+vec[size/2-1])/2:vec[size/2];
}

#endif //C_EXAMPLES_MEDIAN_H
