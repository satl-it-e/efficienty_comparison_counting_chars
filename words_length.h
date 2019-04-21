//
// Created by Sofiia Tesliuk on 2019-04-07.
//

#ifndef EFFICIENTY_COMPARISON_COUNTING_CHARS_WORDS_LENGTH_H
#define EFFICIENTY_COMPARISON_COUNTING_CHARS_WORDS_LENGTH_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace boost;


int* read_by_separate_words(std::string& in_filename);


auto read_entire_file(std::string& in_filename);


int* read_entire_file_boost(std::string& in_filename);


bool my_isalpha(char ch);


int* read_entire_file_isalpha(std::string& in_filename);

#endif //EFFICIENTY_COMPARISON_COUNTING_CHARS_WORDS_LENGTH_H
