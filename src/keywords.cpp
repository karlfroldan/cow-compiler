#include "keywords.hpp"

#include <list>
#include <iostream>
#include <cstdlib>

Keyword find_keyword(std::string input) {
    if (input == "moo") {
        return moo;
    } else if (input == "mOo") {
        return mOo;
    } else if (input == "moO") {
        return moO;
    } else if (input == "mOO") {
        return mOO;
    } else if (input == "Moo") {
        return Moo;
    } else if (input == "MOo") {
        return MOo;
    } else if (input == "MoO") {
        return MoO;
    } else if (input == "MOO") {
        return MOO;
    } else if (input == "OOO") {
        return OOO;
    } else if (input == "OOM") {
        return OOM;
    } else if (input == "oom") {
        return oom;
    } else if (input == "MMM") {
        return MMM;
    } else {
        std::cout << "'" << input << "' is invalid COW operator. Exiting..." << std::endl;
        std::exit(1);
    }
}

std::vector<Keyword> to_keywords(std::string input_str, char delim = ' ') {
    auto n { input_str.size() };
    std::vector<Keyword> program_vector;
    // split
    size_t pos {0};
    std::string token;

    while ((pos = input_str.find(delim)) != std::string::npos) {
        token = input_str.substr(0, pos);
        
        program_vector.push_back(find_keyword(token));

        input_str.erase(0, pos + 1);
    }
    program_vector.push_back(find_keyword(input_str));
    return program_vector;
}