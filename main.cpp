#include "virtualmachine.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

#include <cctype>
#include <locale>

// https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

int main(int argc, char* argv[]) {
    // Program parser("Moo moo OOO");
    if (argc == 1) {
        std::cout << "No Moo file passed. Exiting..." << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream f (argv[1]);
    std::stringstream buffer;

    buffer << f.rdbuf();

    auto s { buffer.str()};

    s.erase(std::remove(s.begin(), s.end(), '\n'), s.cend());
    trim(s);
    
    VirtualMachine vm(10, s);

    vm.run_program();

    return EXIT_SUCCESS;
}