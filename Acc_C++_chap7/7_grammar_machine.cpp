//
// Created by rico on 6/27/19.
//
/*Read me:
 * Data structures: grammar (or grammar book) is a map<string category_name,vector<string> rules(words or phrases)>
 * The core algorithm is gen_aux, which is iterative. It starts from <sentence>, and then it selects a random element A from it.
 * Once the element A is selected, all subelements of A will be executed by plugging into the next iteration:
 * if the chosen sub-element is not a category, it will be push_backed to the sentence; if it is, then it will be decomposed like its upper level categorty.
 */
#include "7_grammar_machine.h"
#include <iostream>
#include <map>
#include<fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstddef>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::ifstream;
using std::string;
using std::vector;
using std::find_if;

void grammar_parser()
{
    ifstream in_file("grammar.txt");
    if(in_file)
    {
        grammar_def grammar;
        read_grammar(in_file,grammar);      // grammar 的key是category, 每个element 都是一个rule（词汇，语法）
        if(grammar.empty()) cout<<"Grammar loading failed!"<<endl;
        else{
            cout<<"How many sentences do you want to generate? "<<endl;
            int num;
            cin>>num;
            for(int i = 0; i<num;++i)
            {
                rule_collection sentence;
                generate_sentence(grammar,sentence);
                print(sentence);
            }
        }
    }
    else
        cout<<"Input file is not found!"<<endl;
}

void read_grammar(ifstream& in_file, grammar_def& grammar)
{
    string line;
    while (getline(in_file,line))
    {
        if (!line.empty())     //ignore_empty line
        {
            rule_collection entry;
            split_category(line,entry);     // 建议写entry = split_category(line);, 将一个句子拆成两个词。　
            if(is_category(entry[0]))       // 若entry 第一个element不是category，那么就不做任何事。 但是entry 只有两个element？
            {
                /*for (auto i = ++entry.begin();i!=entry.end();++i)           //if entry contains only 1 element, the element is to be skipped.
                {
                    grammar[entry[0]].push_back(*i);
                }*/
                grammar[entry[0]].push_back(entry[1]);
            }

        }

    }

}

void split_category(const string& line, rule_collection& entry)
{
    string::const_iterator beg = line.begin(), end = line.end(), temp = beg;
    temp = find(beg,end,' ');
    if(temp!=end)
    {
        entry.push_back(string(beg,temp));
        beg = find_if(temp,end,not_space);
        entry.push_back(string(beg,end));
    }
}

void split(const string& line,rule_collection& entry)
{
    string::const_iterator beg = line.begin(), end = line.end();
    while (beg!= end)
    {
        beg = find_if(beg,end,not_space);
        if(beg!=end)
        {
            string::const_iterator space_temp = find(beg,end,' ');
            entry.push_back(string(beg,space_temp));
            //cout<<" split:"<<string(beg,space_temp);
            beg = space_temp;
        }
    }
}

bool not_space(char c)
{
    return !(c==' ');
}

bool is_category(const rule_def& s)
{
    return s[0]=='<'&&s[s.size()-1]=='>';       // 不要用strlen，用str.size()!
}
void generate_sentence(const grammar_def& grammar_book,rule_collection& sentence)       // TODO: why adding this extra layer? Answer: Because you need to call the iterative function somewhere and you don't wanna get too messy.
{
    rule_def starting_cate = "<sentence>";
    gen_aux(grammar_book,starting_cate,sentence);
}
void gen_aux(const grammar_def& grammar_book, rule_def& rule, rule_collection& sentence)
{
    if (!is_category(rule))                 // End-of-case Scenario
    {
        sentence.push_back(rule);
    }
    else
    {
        grammar_def::const_iterator itr= grammar_book.find(rule);   //this returns vector<string>
        if(itr!=grammar_book.end())
        {
            rule_collection new_rule_collection = itr->second;      // getting the whole collection of rules
            rule_collection::size_type r = rand_num(new_rule_collection.size());        // you randomly choose a new rule
            rule_def new_rule = new_rule_collection[r];
            rule_collection splitted_new_rule;      //split the new rule
            split(new_rule,splitted_new_rule);
            for(auto i = splitted_new_rule.begin();i!=splitted_new_rule.end();++i)      //parse the whole new rule
            {
                gen_aux(grammar_book, *i, sentence);
            }
        }
    }
}

rule_collection::size_type rand_num(rule_collection::size_type n)
{
    rule_collection::size_type r, remainder = RAND_MAX%n, result;
    do{
        r = rand();
    }
    while(r>=RAND_MAX-remainder);       // only [0,n*m) 才可以被采用，离RAND_MAX 太近者一概不会被采用。
    result = r%n;
    return result;
}


void print(const rule_collection& sentence)
{
    for(auto i = sentence.begin();i!=sentence.end();++i)
    {
        cout<<" "<<*i;
    }
    cout<<'.'<<endl;
}