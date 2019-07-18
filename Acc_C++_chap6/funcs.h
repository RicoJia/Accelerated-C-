//
// Created by rico on 6/11/19.
//

#ifndef C_EXAMPLES_FUNCS_H
#define C_EXAMPLES_FUNCS_H

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

void palindrome_main();
void url_finder();
std::string::const_iterator url_beg(std::string::const_iterator,std::string::const_iterator);
std::string::const_iterator url_end(std::string::const_iterator in_beg, std::string::const_iterator in_end);
bool not_url_ch(char);
bool not_alpha_num(char);
void print_str_vec(const std::vector<std::string>&);

void hw_3();
#endif //C_EXAMPLES_FUNCS_H
