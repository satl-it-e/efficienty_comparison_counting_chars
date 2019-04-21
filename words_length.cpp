//
// Created by Sofiia Tesliuk on 2019-04-01.
//


#include "words_length.h"


// Reading by separate words
int* read_by_separate_words(std::string& in_filename){
    std::ifstream in_file(in_filename);
    static int words_length[31] = {0};
    std::string word;

    if (in_file.good()){
        while (in_file >> word){
            words_length[word.length()]++;
        }
    } else{
        std::cout << "Something gone wrong with file" << std::endl;
        return words_length;
    };

    in_file.close();
    return words_length;
}


auto read_entire_file(std::string& in_filename){
    std::ifstream in_file(in_filename);
    auto ss = std::ostringstream{};
    ss << in_file.rdbuf();
    in_file.close();
    return ss.str();
}


// Reading entire file to memory and spliting with boost library
int* read_entire_file_boost(std::string& in_filename){
    static int words_length[31] = {0};
    std::string file = read_entire_file(in_filename);


    std::vector<std::string> SplitVec; // #2: Search for tokens
    split( SplitVec, file, is_any_of(" ,.;:?!()\t\n"), token_compress_on );

    for (const std::string &word: SplitVec){
        words_length[word.length()] += 1;
    }
    return words_length;
}


bool my_isalpha(char ch){
    return ((((int) 'a' <= (int) ch) && ((int) 'z' >= (int) ch)) ||
            (((int) 'A' <= (int) ch) && ((int) 'Z' >= (int) ch)));
}

// Reading entire file to memory and determining length with isalpha
int* read_entire_file_isalpha(std::string& in_filename){
    static int words_length[31] = {0};
    std::string file = read_entire_file(in_filename);

    int length = 0;
    for (char some_letter: file){
        if (my_isalpha(some_letter)){
            length++;
        } else{
            if (length > 0){
                words_length[length]++;
            }
            length = 0;
        }
    }
    return words_length;
}