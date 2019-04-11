//
// Created by Sofiia Tesliuk on 2019-04-01.
//


#include "words_length.h"



// Reading by separate words
int* read_by_separate_words(std::string& in_filename){
    std::ifstream in_file(in_filename);
    static int words_length[256] = {0};
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

//
//template <typename CharT, typename Traits,
//        typename Allocator = std::allocator<CharT>>
//auto read_stream_into_string(
//        std::basic_istream<CharT, Traits>& in,
//        Allocator alloc = {})
//{
//    std::basic_ostringstream<CharT, Traits, Allocator>
//            ss(std::basic_string<CharT, Traits, Allocator>(
//            std::move(alloc)));
//
//    if (!(ss << in.rdbuf())){
//            throw std::ios_base::failure{"error"};
//    }
//
//    return ss.str();
//}

auto read_entire_file(std::string& in_filename){
    std::ifstream in_file(in_filename);
    auto ss = std::ostringstream{};
    ss << in_file.rdbuf();
    in_file.close();
    return ss.str();
}

// Read entire file (two copies)
int* read_entire_file_boost(std::string& in_filename){
    std::ifstream in_file(in_filename);

    static int words_length[256] = {0};
    std::string file = read_entire_file(in_filename);


    std::vector<std::string> SplitVec; // #2: Search for tokens
    split( SplitVec, file, is_any_of(" ,.;:?!()'\t\n"), token_compress_on ); // SplitVec == { "hello abc","ABC","aBc goodbye" }

    for (const std::string &word: SplitVec){
        words_length[word.length()] += 1;
    }
    return words_length;
}


// Read entire file (one copy)
int* read_entire_file_1(std::string& in_filename){
    std::ifstream in_file(in_filename);
    static int words_length[256] = {0};
    in_file.close();
    return words_length;
}