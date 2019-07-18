//
// Created by rico on 5/31/19.
//

#include "frame_width.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::max;

string::size_type width(const vector<string>& msgs) {
    string::size_type maxlen = 0;
    for (auto i = msgs.begin(); i != msgs.end(); ++i)
    {
        maxlen = max(maxlen,(*i).size());
    }
    return maxlen;
}

vector <string> frame(const vector<string>& msgs)
{
    string::size_type wid = width(msgs)+4;
    vector<string> ret;
    string top(wid,'*');
    ret.push_back(top);

    for(auto i = msgs.begin(); i!= msgs.end();++i)
    {
        string::size_type wid_local =(*i).size();
        string temp = string(wid-wid_local-4,' '); //white space
        temp = "**"+(*i)+temp+"**";
        ret.push_back(temp);
    }
    ret.push_back(top);
    return ret;
}