#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <string>
#include "time_measure.h"
#include "words_length.h"


int main(int argc, char *argv[]) {
    int method_id;
    std::string in_filename, out_filename;

    if (argc < 4){
        std::cout << "Too few arguments. Should be <method_id> <input_file> <result_file>" << std::endl;
        return -1;
    } else{
        // Getting method id
        std::istringstream iss( argv[1] );
        int val;

        if (iss >> val)
        {
            method_id = val;
            if ((method_id < 1) || (method_id > 3)){
                std::cout << "Id of methods are in range [1; 3]" << std::endl;
                return -3;
            }

        } else{
            std::cout << "Invalid first argument. Should be an integer -- method id" << std::endl;
            return -2;
        }

        in_filename = argv[2];
        out_filename = argv[3];

        int* results;

        // Opening files
        if (!in_filename.empty() || !out_filename.empty()){
            // Open file

                auto start = get_current_time_fenced();
                switch (method_id) {
                    case 1:
                        results = read_by_separate_words(in_filename);
                        break;
                    case 2:
                        results = read_entire_file_boost(in_filename);
                        break;
                    case 3:
                        results = read_entire_file_1(in_filename);
                        break;
                }

                auto finish = get_current_time_fenced();

                std::ofstream out_file(out_filename, std::ios_base::app);
                if (out_file.good()){
                    int mean = 0, number_of_words = 0;
                    for(int i = 1; i < 256; i++){
                        number_of_words += results[i];
                        mean += i * results[i];
                    }
                    out_file << "Total time of processing: " << to_us(finish - start) << std::endl;
                    out_file << "Average word length: " << mean / number_of_words << std::endl;
                    for(int i = 1; i < 256; i++){
                        out_file << "Word length: " << i << " Number of words: " << results[i] << std::endl;
                    }

                } else {
                    std::cout << "Something gone wrong with output file" << std::endl;
                    return -5;
                }

            }
        }





    return 0;
}