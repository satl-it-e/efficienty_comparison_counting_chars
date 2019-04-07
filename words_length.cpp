//
// Created by Sofiia Tesliuk on 2019-04-01.
//


#include "words_length.h"


// Reading by separate words
int* read_by_separate_words(std::ifstream in_file){
    static int words_length[256] = {0};
    std::string word;

    if (in_file.good()){
        while (in_file >> word){
            words_length[word.length()]++;
        }
    }
    in_file.close();
    return words_length;
}


// Read entire file (two copies)
int* read_entire_file_2(std::ifstream in_file){
    static int words_length[256] = {0};
    auto ss = std::ostringstream{};
    ss << in_file.rdbuf();
    auto s = ss.str();
    in_file.close();
    return words_length;
}


// Read entire file (one copy)
int* read_entire_file_1(std::ifstream in_file){
    static int words_length[256] = {0};
    in_file.close();
    return words_length;
}