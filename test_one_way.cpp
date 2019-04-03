#include <iostream>
#include <vector>
#include <string>


template <class InputIt, class ForwardIt, class BinOp>
void for_each_token(InputIt first, InputIt last,
                    ForwardIt s_first, ForwardIt s_last,
                    BinOp binary_op)
{
    while (first != last) {
        const auto pos = std::find_first_of(first, last, s_first, s_last);
        binary_op(first, pos);
        if (pos == last) break;
        first = std::next(pos);
    }
}


std::vector<std::string>
split(const std::string& str, const std::string& delims = " ",
      bool skip_empty = true)
{
    std::vector<std::string> output;
    for_each_token(cbegin(str), cend(str),
                   cbegin(delims), cend(delims),
                   [&output] (auto first, auto second) {
                       if (first != last || !skip_empty) {
                           output.emplace_back(first, second);
                       }
                   });
    return output;
}

int alg_2(){
    return 0;
};

int alg_3(){
    return 0;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}