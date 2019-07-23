//
// Created by rico on 7/19/19.
//

#ifndef ACCELERATED_C_8_5_H
#define ACCELERATED_C_8_5_H

#include <map>
#include <fstream>
#include <vector>
#include <string>

typedef std::string rule_def;
typedef std::vector<std::string> rule_collection;
typedef std::map<std::string,rule_collection> grammar_def;

void test_8_5();
void read_grammar(std::ifstream& in_file, std::map<std::string,std::vector<std::string> >&);
void split_category(const std::string& line, rule_collection& entry);
void split(const std::string& line,rule_collection& entry);
bool not_space(char c);
bool is_category(const rule_def&);
rule_collection::size_type rand_num(rule_collection::size_type);
//----------------------------------------------------------------------------
void read_in(std::vector<std::string>& input, std::istream& in_file);
void add_url_words_2_T(std::map<std::string,std::vector<int> >& url_map,std::map<std::string,std::vector<int> >& word_map,const std::vector<std::string>& input);
int test_xref();
std::string::const_iterator url_beg(std::string::const_iterator,std::string::const_iterator);
std::string::const_iterator url_end(std::string::const_iterator in_beg, std::string::const_iterator in_end);
bool not_url_ch(char);
#endif //ACCELERATED_C_8_5_H
