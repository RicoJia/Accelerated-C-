//
// Created by rico on 6/27/19.
//

#ifndef C_EXAMPLES_7_GRAMMAR_MACHINE_H
#define C_EXAMPLES_7_GRAMMAR_MACHINE_H

#include <map>
#include <fstream>
#include <vector>
#include <string>

typedef std::string rule_def;
typedef std::vector<std::string> rule_collection;
typedef std::map<std::string,rule_collection> grammar_def;

void grammar_parser();

void read_grammar(std::ifstream& in_file, std::map<std::string,std::vector<std::string> >&);

void split_category(const std::string& line, rule_collection& entry);
void split(const std::string& line,rule_collection& entry);
bool not_space(char c);

bool is_category(const rule_def&);

void generate_sentence(const grammar_def&,rule_collection&);
void gen_aux(const grammar_def&, rule_def&, rule_collection&);
rule_collection::size_type rand_num(rule_collection::size_type);

void print(const rule_collection&);

#endif //C_EXAMPLES_7_GRAMMAR_MACHINE_H
