//
// Created by rico on 6/24/19.
//

#ifndef C_EXAMPLES_7_TEXTBOOK_H
#define C_EXAMPLES_7_TEXTBOOK_H

#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

void word_counter();

void url_word_xref();
void read_in(vector<string>& input);
void add_url_words_2_map(map<string,vector<int> >&,map<string,vector<int> >&,const vector<string>&);
void print_map(const map<string,vector<int> >&);

vector<string> split(const string&);

#endif //C_EXAMPLES_7_TEXTBOOK_H
