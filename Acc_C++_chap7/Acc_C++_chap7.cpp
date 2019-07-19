//
// Created by rico on 6/5/19.
//This file includes: 1. word counter using map
// 2. a cross-reference table that links word with in which line of input it was at. vector<int>, and the split func from chap 5.
//3. write a random sentence generator, that reads grammar from a file, then select random words according to the grammar rule.space in bw words.


#include <map>
#include <iostream>
#include <iterator>
#include "7_textbook.h"
#include <string>
#include "7_grammar_machine.h"

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::cin;

using std::ostream_iterator;
using std::istream_iterator;

int main()
{
    grammar_parser();
   // url_word_xref();

   return 0;
}





