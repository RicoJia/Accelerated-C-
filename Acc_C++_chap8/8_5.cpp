//
// Created by rico on 6/27/19.
//
/*Read me:
 * This is an enhancement of chap7 grammar machine exercise. The program uses output iterator to print out words in real time.
 * Data structures: grammar (or grammar book) is a map<string category_name,vector<string> rules(words or phrases)>
 * The core algorithm is gen_aux, which is iterative. It starts from <sentence>, and then it selects a random element A from it.
 * Once the element A is selected, all subelements of A will be executed by plugging into the next iteration:
 * if the chosen sub-element is not a category, it will be push_backed to the sentence; if it is, then it will be decomposed like its upper level categorty.
 */
#include "8_5.h"
#include <cctype>           //isalpha

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
#include <map>
using std::map;

#include<fstream>
using std::ifstream;

#include <string>
using std::string;

#include <algorithm>
using std::find_if;
using std::search;

#include <cstring>
#include <cstddef>
#include <cstdlib>
#include <iterator>
using std::ostream_iterator;

#include <sstream>
using std::stringstream;

#include <vector>
using std::vector;


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


template <typename T>
void gen_aux(const grammar_def& grammar_book, rule_def& rule, T& output_iter)
{
    if (!is_category(rule))                 // End-of-case Scenario
    {
        *output_iter = rule;              //back_inserter ++
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
                gen_aux(grammar_book, *i, output_iter);
            }
        }
    }
}

template <typename T>
void generate_sentence(const grammar_def& grammar_book,T output_iter)       // TODO: why adding this extra layer? Answer: Because you need to call the iterative function somewhere and you don't wanna get too messy.
{
    rule_def starting_cate = "<sentence>";
    gen_aux(grammar_book,starting_cate,output_iter);
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


void test_8_5()
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
                generate_sentence(grammar,ostream_iterator<string>(cout," "));
                cout<<endl;
            }
        }
    }
    else
        cout<<"Input file is not found!"<<endl;
}

//--------------------------------------------------------------------------------------------------
void read_in(vector<string>& input, istream& in_file)
{
    string line;
    while(getline(in_file,line))
    {
        input.push_back(line);
    }
}

void add_url_words_2_T(map<string,vector<int> >& url_map,map<string,vector<int> >& word_map,const vector<string>& input)
{
    for(auto i = 0;i<input.size();++i )
    {
        vector<string> word_breakdown; split(input[i],word_breakdown);        // break down each word.
        for (auto j = word_breakdown.begin();j!=word_breakdown.end();++j)
        {
            string::const_iterator beg = (*j).begin(), end = (*j).end();
            while (beg!=end)
            {
                string::const_iterator temp = beg;
                beg = url_beg(beg,end);     //find where a valid url begins
                if(beg!=end)
                {           //URL is found
                    string::const_iterator after = url_end(beg,end);
                    url_map[string(beg,after)].push_back(i);
                    beg = after;
                }
                else if (temp!=beg) word_map[string(temp,beg)].push_back(i);        // push back non-empty string as a word
            }
        }

    }
}

template<typename T>
void url_word_xref(T output_iter, istream& in_file)
{
    vector<string> input;
    read_in(input,in_file);                         // read in your input. Can be as messy as SDF!@#
    map<string,vector<int> > url_map,word_map;
    add_url_words_2_T(url_map,word_map,input);
    cout<<"--------------------------------------"<<endl<<"url results: "<<endl;
    for (auto i = url_map.begin();i!=url_map.end();++i)
    {
        stringstream ss;
        ss<<i->first<<" has appeared in lines";
        for (auto j = i->second.begin();j!=i->second.end();++j)
        {
            ss<<" "<<*j;
        }
        ss<<endl;
        *output_iter++ = ss.str();
    }
    cout<<"--------------------------------------"<<endl<<"word results"<<endl;
    for (auto i = word_map.begin();i!=word_map.end();++i)
    {
        stringstream ss;
        ss<<i->first<<" has appeared in lines";
        for (auto j = i->second.begin();j!=i->second.end();++j)
        {
            ss<<" "<<*j;
        }
        ss<<endl;
        *output_iter++ = ss.str();
    }

}

int test_xref()
{
    ifstream in_file("xref_input.txt");
    if(in_file)
        url_word_xref(ostream_iterator<string>(cout, " "),in_file);
    return 0;
}

std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e)       //returns e if nothing is found
{
    typedef string::const_iterator iter;
    static const string mark = "://";
    string::size_type size = mark.size();
    //iter i = find(b,e,mark);
    iter i = search(++b,e,mark.begin(),mark.end()); //i cannot be the first element.
    while(i!=b&&i!=e){    // return the iterator of the first valid item
        if((i+size)==e) return e;
        if(not_url_ch(i[size])||!isalpha(*(i-1)))
            i = search(i+size,e,mark.begin(),mark.end());
        else
            //found a valid url's existence, then let's find the beginning of the address
        {
            while (i >= b && isalpha(i[-1]))
                --i;
            break;  // break out of this loop once we have found the beginning of the address.
        }
    }

    return i;
}

std::string::const_iterator url_end(std::string::const_iterator in_beg, std::string::const_iterator in_end)   // we know input already has alphabetic before "://"
{
    return find_if(in_beg,in_end,not_url_ch);
}

bool not_url_ch(char c)
{
    static const string sym= "~;/?:@=&$-_.+!*'(),";
    // return not_alpha_num(c)&&(find(sym.begin(),sym.end(),c)==sym.end());
    return !isalnum(c)&&(find(sym.begin(),sym.end(),c)==sym.end());

}