#include <iostream>


#include "virtualmachine.hpp"


int main(int argc, char* argv[]) {
    // Program parser("Moo moo OOO");

    if (argc == 1) {
        std::cout << "No Moo file passed. Exiting..." << std::endl;
        return EXIT_FAILURE;
    }

    

    VirtualMachine vm(10, "Moo moo OOO");

    return EXIT_SUCCESS;
}